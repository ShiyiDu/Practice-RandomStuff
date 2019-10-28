#include <stdio.h>

int main(int argc, char *argv[]) {
	char result[101], temp;
	result[0] = getchar();
	int char_count = 1;
	while ((temp = getchar()) != '\n') {
		if(temp == '-') {
			result[char_count] = getchar();
			char_count ++;
		}
	}
	result[char_count] = '\0';
	
	printf("%s", result);
}