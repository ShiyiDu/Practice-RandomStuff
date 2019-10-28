#include <stdio.h>

int myFunction();
int main(); //this line is unnecessary

int main() {
	int i0 = 0;
	int i1 = 1;
	int i2 = 2;
	
	int* ptr= &i0;
	int* ptr1 = &i1;
	int* ptr2 = &i2;
	
	printf("%i\n",*ptr);
	printf("0x%x\n",ptr);
	printf("0x%x\n",ptr1);
	printf("0x%x\n",ptr2);

	return 0;
}