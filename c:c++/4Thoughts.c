#include <stdio.h>

int cal(int nums[], int num_len, char op[], int op_len);

int main(int argc, char *argv[]) {
	int all_outcomes[64][4];
	char ops[3];
	for(int i = 0; i < 4; i++){
		ops[0] = i == 0 ? '+' : i == 1 ? '-' : i == 2 ? '*' : '/';
		for(int j = 0; j < 4; j++){
			ops[1] = j == 0 ? '+' : j == 1 ? '-' : j == 2 ? '*' : '/';
			for(int k = 0; k < 4; k++){
				ops[2] = k == 0 ? '+' : k == 1 ? '-' : k == 2 ? '*' : '/';
				int outcome_index = i * 16 + j * 4 + k;
				
				int nums[4] = {4,4,4,4};
//				printf("%d\n", outcome_index);
				all_outcomes[outcome_index][0] = cal(nums, 4, ops, 3);
				all_outcomes[outcome_index][1] = ops[0];
				all_outcomes[outcome_index][2] = ops[1];
				all_outcomes[outcome_index][3] = ops[2];
			}
		}
	}
	
	int num_of_cases;
	scanf("%d", &num_of_cases);
	int result[num_of_cases];
	for(int i = 0; i < num_of_cases; i++){
		int target;
		scanf("%d", &target);
		for(int j = 0; j < 64; j++){
			if(all_outcomes[j][0] == target){
				result[i] = j;
				break;
			}
			result[i] = -1;
		}
	}
	
	for(int i = 0; i < num_of_cases; i++){
		int answer_index = result[i];
		if(answer_index == -1){
			printf("no solution\n");
		}else {
			printf("4 %c 4 %c 4 %c 4 = %d\n", all_outcomes[answer_index][1],all_outcomes[answer_index][2],all_outcomes[answer_index][3],all_outcomes[answer_index][0] );
		}
	}
//	
//	for(int i = 0; i < 64; i++){
//		printf("%d \n", all_outcomes[i][0]);
//	}
}

int cal(int nums[], int num_len, char op[], int op_len){
	int marker[num_len];
	for(int i = 0; i < num_len; i++){
		marker[i] = 0;
	}
	for(int i = 0; i < op_len; i++){
		if(op[i] == '*'){
			nums[i + 1] = nums[i] * nums[i + 1];
			marker[i] = 1;
		}else if(op[i] == '/'){
			nums[i + 1] = nums[i] / nums[i + 1];
			marker[i] = 1;
		}
	}
	
	for (int i = 0; i < op_len; i++) {
		if(op[i] == '+'){
			int num_one = i;
			while (marker[num_one]) {
				num_one++;
			}
			int num_two = num_one + 1;
			while (marker[num_two]) {
				num_two++;
			}
			nums[num_two] = nums[num_one] + nums[num_two];
			marker[num_one] = 1;
		}else if(op[i] == '-'){
			int num_one = i;
			while (marker[num_one]) {
				num_one++;
			}
			int num_two = num_one + 1;
			while (marker[num_two]) {
				num_two++;
			}
			nums[num_two] = nums[num_one] - nums[num_two];
			marker[num_one] = 1;
		}
	}
	
	return nums[num_len-1];
}