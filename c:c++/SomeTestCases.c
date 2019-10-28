#include <stdio.h>
#include <stdlib.h>

int ChangeValue(int input, int* p_input);
int ChangeArray(int array[], int length);
typedef unsigned int uint;
typedef long long int lint;

int main(void) {
	lint long_int = 113;
	uint unsigned_integer = 11;
	int binary = 0b10;
	int integer = 10;
	int array[10] = {0,1,2,3,4,5,6,7,8,9};
	char *str;
	str = (char *)malloc(20);
	str[0] = 'h';
	str = "this is a test";
	
	printf("\nthe string is ’%s‘", str);
	//I guess c does not allow you to copy a value of an array to another array.
//	int array_2[10] = array;
	ChangeValue(integer, &integer);
	ChangeArray(array, 10);
	printf("\n int pointer size: %lu", sizeof(int *)/ sizeof(int));
	printf("\n char pointer size: %lu", sizeof(char *)/ sizeof(int)); //the pointer size is 8 Byte in a 64-bit based system I guess.
	printf("\nlong integer: %lld", long_int);
	printf("\nunsigned integer: %u", unsigned_integer);
	printf("\n%d", array[0]);
	printf("\ninteger: %d", integer);
	printf("\nsize in main :%lu", sizeof(array)/sizeof(int));
	return 1;
}

int ChangeArray(int array[], int length){
	//when the array is passed in to a function, you can only pass the pointer,
	//but the function will treate it like an array except that the size information are missing???
	array[0] = 200;
//	int array_1[length] = array;
	printf("\nsize under function: %lu", sizeof(&array[0])/sizeof(int));
	return 1;
}

int ChangeValue(int input, int* p_input){
	input = 20;
	*p_input = 20;
	return 1;
}