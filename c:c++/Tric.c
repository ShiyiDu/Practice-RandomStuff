#include <stdio.h>

void swap(short *a, short *b);

int main(int argc, char *argv[]) {
	short one, two, three;
	one = 1; two = 0; three = 0;
	char holder;
	while ((holder = getchar()) != '\n') {
		switch (holder) {
			case 'A':
				swap(&one, &two);
				break;
			case 'B':
				swap(&three, &two);
				break;
			case 'C':
				swap(&one, &three);
				break;
			default:
				break;
		}
	}
	
	printf(one ? "1" : two ? "2" : "3");
}

void swap(short *a, short *b){
	short temp = *a;
	*a = *b;
	*b = temp;
}