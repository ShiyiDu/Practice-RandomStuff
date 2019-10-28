#include <stdio.h>
int trial(float p, int n);

static int calculations = 0;
int main(int argc, char *argv[]) {
	
	
	for (int i = 0; i < 1; i++) {
		printf("%d, ", trial(0.75, 100000000));
	}
	
	printf("\n%d", calculations);
}

int trial(float p, int n){
	int result = 0, success;
	float toss = 1;
	for(int i = 0; i < n; i++){
		success = 0;
		toss = 1;
		while (toss >= p) {
			success += 1;
			toss = ((float)(rand() % 10000) / 10000);
			calculations ++;
		}
		
		result += success;
	}
	
	return result/n;
}