#include <stdio.h>

#define MAX_SIZE_VALUE 1000000

void Add(int can_size);
int Contains(int can_size);
int HashCode(int can_size);

int all_size[1000001];

int main(void) {
	int number_of_size, number_of_color;
	unsigned long long int result;
	scanf("%d %d", &number_of_size, &number_of_color);
	int all_color[number_of_color];
	
	for (int i = 0; i < number_of_size; i++) {
		int temp;
		scanf("%d", &temp);
		Add(temp);
	}
	
	for (int i = 0; i < number_of_color; i++) {
		int temp;
		scanf("%d", &temp);
		all_color[i] = temp;
	}
	
	result = 0;
	int* current_color;
	for (int i = 0; i < number_of_color; i++) {
		current_color = &all_color[i];
		for (int j = *current_color; ;j++) {
			if(Contains(j) == 1){
				result += j - *current_color;
				break;
			}
		}
	}
	
	printf("%llu", result);
}