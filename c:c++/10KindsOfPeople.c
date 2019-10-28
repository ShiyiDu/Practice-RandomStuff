#include <stdio.h>
#include <stdlib.h>

#define TOTAL_GRIDS r_length * c_length

int PathExists(int r0, int c0, int r1, int c1, int total_grids);
int GetType(int index);
int GetLeft(int index);
int GetUp(int index);
int GetRight(int index);
int GetDown(int index);

int *map;
int r_length;
int c_length;

int main() {
	scanf("%d %d", &r_length, &c_length);
	
	map = (int *)malloc(r_length * c_length * sizeof(int));
	
	for(int r = 0; r < r_length; r++){
		char line[c_length + 1];
		scanf("%s", line);
		for (int c = 0; c < c_length; c++) {
			int index = r * c_length + c;
			
			map[index] = line[c] - 48;
		}
	}
	
	int num_of_pairs = 0;
	scanf("%d", &num_of_pairs);
	
	int results[num_of_pairs];
	for(int i = 0; i < num_of_pairs; i++){
		int r0, c0, r1, c1;
		scanf("%d %d %d %d", &r0, &c0, &r1, &c1);
		r0--; c0--; r1--; c1--;
		results[i] = PathExists(r1, c1, r0, c0, TOTAL_GRIDS);
	}
	
	for(int i = 0; i < num_of_pairs; i++){
		switch (results[i]) {
			case 0:
				printf("binary\n");
				break;
			case 1:
				printf("decimal\n");
				break;
			case -1:
				printf("neither\n");
				break;
			default:
				printf("something wend wrong!!");
		}
	}
	
}

int PathExists(int r0, int c0, int r1, int c1, int total_grids){
	int start_index = r0 * c_length + c0;	
	int target_index = r1 * c_length + c1;
	
	int type = GetType(start_index);
	int open_list[total_grids];
	int close_list[total_grids];
	int done_search = 0;
	if(type != GetType(target_index)) return -1;
	
	for (int i = 0; i < total_grids; i++) {
		open_list[i] = 0;
		close_list[i] = 0;
	}
	
	open_list[start_index] = 1;
	while (!done_search) {
		done_search = 1;
		for (int i = 0; i < total_grids; i++) {
			if(close_list[i]) continue; //if its already searched, continue next search
			if(!open_list[i]) continue; //if its not a possible path, continue next search
			if(i == target_index) return type; //if the node is the destination, path found
			int left = GetLeft(i); //if left grid is a valid grid, add it to open list for search
			int up = GetUp(i);
			int right = GetRight(i);
			int down = GetDown(i);
			
			if(!close_list[left] && GetType(left) == type) open_list[left] = 1;
			if(!close_list[up] && GetType(up) == type) open_list[up] = 1;
			if(!close_list[right] && GetType(right) == type) open_list[right] = 1;
			if(!close_list[down] && GetType(down) == type) open_list[down] = 1;
			close_list[i] = 1;
			open_list[i] = 0;
			done_search = 0;
		}
	}
	
	return -1;
}

int GetType(int index){
//	int r = index / r_length;
//	int c = index % r_length;
//	
//	int position = r * r_length + c;
	return map[index];
}

int GetLeft(int index){
	int r = index / c_length;
	int c = index % c_length;
	
	if(c == 0) return -1;
	return r * c_length + c - 1;
}

int GetUp(int index){
	int r = index / c_length;
	int c = index % c_length;
	
	if(r == 0) return -1;
	return (r - 1)* c_length + c;
}

int GetRight(int index){
	int r = index / c_length;
	int c = index % c_length;
	
	if(c == c_length - 1) return -1;
	return r * c_length + c + 1;
}

int GetDown(int index){
	int r = index / c_length;
	int c = index % c_length;
	
	if(r == r_length - 1) return -1;
	return (r + 1)* c_length + c;
}