#include <stdio.h>
#include <math.h>

int main(void) {
	int input, digits, comparer_0, comparer_1, holder;
	int result = 0;
	scanf("%d", &input);
	if(input == 0) return 0;
	
	digits = 0;
	holder = input;
	
	while (holder != 0) {
		holder /= 10;
		digits ++;
	}
	
	char all_digit[digits];
	for(int i = digits - 1; i >= 0; i--){
		all_digit[i] = (char)((input / (int)pow(10, i)) + 48);
		input = input % (int)pow(10, i);
//		printf("\n%c", all_digit[i]);
	}
	
	comparer_0 = 0;
	comparer_1 = digits - 1;
	
	while (comparer_1 > comparer_0) {
		if(all_digit[comparer_1] != all_digit[comparer_0]) printf("its not a mirror");
		comparer_0++;
		comparer_1--;
	}
	
	return 0;
}