#include <stdio.h>
#include <math.h>
double TapeLength(int a_size);
double MoveForward(int paper[], int length);

int main(void) {
	int num_of_types;
	scanf("%d", &num_of_types);
	int all_paper[num_of_types - 1];
	for(int i = 0; i < num_of_types - 1; i++){
		scanf("%d", &all_paper[i]);
	}
	
	double result = MoveForward(all_paper, num_of_types - 1);
	result += pow(2.0, -0.75);
	if(result < 0){
		printf("impossible\n");
	}else {
		printf("%.11lf\n", result);
	}
}

double MoveForward(int paper[], int length){
	double total_tape = 0;
	int marker[length], current_need, start_index;
	current_need = 2; //2 of A2 paper
	for(int i = 0; i < length; i++){
		current_need -= paper[i];
		marker[i] = current_need;
		if(current_need <= 0) {
			start_index = i;
			break;
		}
		current_need *= 2;
	}
	
	if(current_need > 0) return -1;
	
	for(int i = start_index; i > 0; i--){
		int a_size = i + 2;
		int paper_needed = marker[i-1]*2;
		
		paper[i] -= paper_needed;
		paper[i - 1] += paper_needed/2;
		total_tape += paper_needed / 2 *TapeLength(a_size);
		
	}
	
	return total_tape;
}

double TapeLength(int a_size){
	double width, height, result;
	height = pow(2.0, -0.75);
	width = pow(2.0, -1.25);
	result = 0;
	
	if(a_size % 2 == 0){
		double multiplier = pow(1.0/2.0, (a_size - 2) / 2.0);
		result = multiplier * height;
	}else{
		double multiplier = pow(1.0/2.0, (a_size - 3) / 2.0);
		result = multiplier * width;
	}
	
	return result;
}