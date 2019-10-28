#include <stdio.h>

int main(int argc, char *argv[]) {
	
	char in[100];
	scanf("%s", in);
	int counter = 0;
	while (in[0] != '\0') {
		printf("%s", in);
		counter++;
		if(counter==100) break;
	}
}