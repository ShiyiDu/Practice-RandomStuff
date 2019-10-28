#include <stdio.h>
#include <string.h>

int main(void) {
	int number = 0;
	scanf("%d", &number);
	char molecule[number];
	scanf("%s", &molecule[0]);
	
	char current = 'B';
	int counter = 0;
	
	for (int i = number - 1; i >=0 ; i--) {
		char temp = molecule[i];
		if(i == 0){
			if(temp == current) counter++;
			break;
		}
		if(temp == current && molecule [i-1] == current){
			counter++;
			while (molecule[i]== current) {
				i--;
			}
			i++;
			current = current == 'A' ? 'B' : 'A';
		}else if(temp == current){
			counter++;
		}
	}
	
	printf("%d", counter);
	
	return 0;
}