#include <stdio.h>
#include <stdlib.h>

float ReadTemperature(char serial_number[]);

int main(int argc, char *argv[]) {
	FILE *fd;
	int n;
	char buf[101];
	char str[20] = "TestTemp.txt";
	char sec[5] = "test";
	
	char file_name[] = {"28-01131e7c7bfd"};
	
	float result = ReadTemperature(file_name);
	printf("read: %f", result);
	
}

float ReadTemperature(char serial_number[]){
	char dir[] = "TestTemp.txt";
//	for(int i = 0; i < 15; i++){
//		int index = i + 20;
//		dir[index] = serial_number[i];
//	}
//	
	FILE *fd;
	int n;
	char buf[101];
	
	if((fd = fopen(dir, "r")) == (FILE *)NULL){
		//not read
	}
	
	n = fread(buf, 1, 100, fd);
	buf[n] = '\0';
	
	float result = ((buf[n-3] - 48) * 0.1 + (buf[n-4] - 48) + (buf[n-5] - 48) * 10);
	
	fclose(fd);
	return result;
}