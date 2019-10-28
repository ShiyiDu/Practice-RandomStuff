#include <stdio.h>
#include <math.h>

int countDigits(int x, int d);
int testCountDigits(int x, int d, int result, char *msg);

/* name: Shiyi Du, student number: 214438469 */
int main(int argc, char *argv[]) 
{
	testCountDigits(123, 1, 1, "single digit test");
	testCountDigits(0, 0, 1, "single 0 test");
	testCountDigits(456456, 4, 2, "two fours");
	testCountDigits(111111, 1, 6, "six 1's");
	
	return 0;
}

int testCountDigits(int x, int d, int result, char *msg)
{
	int my_result = countDigits(x, d); 
	
	if(my_result == result){
		printf("test passed %s \n", msg);
	}else {
		printf("test failed %s \n", msg);
	}
	
	return 0;
}

int countDigits(int x, int d)
{
	int digits, holder;
	int result = 0;
	char char_d = (char)d+48;
	
	if(x == 0 && d == 0) return 1;
	
	digits = 0;
	holder = x;
	
	while (holder != 0) {
		holder /= 10;
		digits ++;
	}
	
	char all_digit[digits];
	for(int i = digits - 1; i >= 0; i--){
		all_digit[i] = (char)((x / (int)pow(10, i)) + 48);
		if(all_digit[i] == char_d) result++;
		x = x % (int)pow(10, i);
//		printf("\n%c", all_digit[i]);
	}
	
	return result;
}