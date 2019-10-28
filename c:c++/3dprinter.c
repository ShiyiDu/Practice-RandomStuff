#include <stdio.h>

int main(void) {
	int output_number = 0;	
	char read_input[10];
	char* address = &read_input[0];
	char* address_2 = &read_input[2];
	address_2 ++;
	scanf("%s %s", address, address_2);
	
	printf("%s", read_input);
	
	return 0;
}