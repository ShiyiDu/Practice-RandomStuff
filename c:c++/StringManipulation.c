#include <stdio.h>
#include <math.h>

//#define PI 3.14159265

int ComStr(char a[], char b[]);
int Contain(char all_str[], int str_len, char str[]);
void InitStr(char a[]);
void CopyStr(char a[], char b[]);

int main(int argc, char *argv[]) {
	int num;
	scanf("%d", &num);
	for(int i = 0; i < num; i++) {
		int num_0, counter = 0;
		scanf("%d", &num_0);
		char all_str[num_0][21];
		for(int j = 0; j < num_0; j++) {
			char temp[21];
			InitStr(temp);
			scanf("%s", temp);
			if(Contain(&all_str[0][0], num_0, temp)){
			}else {
				counter++;
				CopyStr(all_str[j], temp);
			}
		}
		printf("%d", counter);
	}
}

void CopyStr(char a[], char b[]){
	for(int i = 0; i < 21; i++){
		a[i] = b[i];
	}
}

int Contain(char all_str[], int str_len, char str[]){
	for(int i = 0; i < str_len; i++){
		if(ComStr(&all_str[i * 21], str)) return 1;
	}
	return 0;
}

void InitStr(char a[]){
	for(int i = 0; i < 20; i++){
		a[i] = 0;
	}
}

int ComStr(char a[], char b[]){
	for(int i = 0; i < 20; i++){
		if(a[i] != b[i]) return 0;
	}
	
	return 1;
}