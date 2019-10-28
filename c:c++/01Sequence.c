#include <stdio.h>

typedef unsigned long long myint;

int main() {
	myint result = 0;
	myint number_of_one = 0;
	myint cases = 1;
	char current;
	
	while ((current = getchar()) != '\n') {
		switch (current) {
			case '0':
				result += number_of_one;
				break;
			case '1':
				number_of_one += cases;
				break;
			case '?':
				result = result << 1;
				result += number_of_one;
				number_of_one = number_of_one << 1;
				number_of_one += cases;
				cases = cases << 1;
				break;
			default:
				break;
		}
		number_of_one %= 1000000007;
		result %= 1000000007;
		cases %= 1000000007;
	}
	printf("%llu", result);
	return 0;
}