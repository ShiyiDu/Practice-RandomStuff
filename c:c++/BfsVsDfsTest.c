#include <stdio.h>
#include <time.h>
#include "Quene.h"

//#define CLOCKS_PER_MS ClOCKS_PER_SEC/1000

int DFS(int r, int c, char type);
int BFS(int r, int c, char type, Quene *quene);
int index(int r, int c);

int rows, columns, rd, cd; char *grids, *marks;
short marker;

int main(int argc, char *argv[]) {
	//create a mase of size 1000 * 1000;
	clock_t clock_start, clock_end;
	int time_used = 0;
	Quene quene = InitQuene();
	
	rows = columns = 220;
		
	grids = malloc(rows * columns * sizeof(char));
	marks = malloc(rows * columns * sizeof(char));
	for(int i = 0; i < rows * columns; i++){
		marks[i] = 0;
		grids[i] = 1;
	}
	rd = cd = 199;
	int r, d;
	r = d = 30;
	clock_start = clock();
	
	for(int i = 0; i < 128; i++) {
		marker = i;
		DFS(r, d, 1);
	}
	clock_end = clock();
	time_used = (clock_end - clock_start) / (CLOCKS_PER_SEC / 1000);
	
	//the dfs search in this kind of grid almost always faster than DFS
	//probably because the quene I implemented is too slow???
	printf("DFS: %d ms\n", time_used);
	for(int i = 0; i < rows * columns; i++){
		marks[i] = 0;
	}
	clock_start = clock();
//	BFS(r, d, 1, &quene);
	clock_end = clock();
	time_used = (clock_end - clock_start) / (CLOCKS_PER_SEC / 1000);
	
//	printf("BFS: %d ms\n", time_used);
	
	
}
//return 0 if no path, 1 if path found
int DFS(int r, int c, char type){
	//DFS
	char result = 0;
	int left = c - 1;
	int up = r - 1;
	int right = c + 1;
	int down = r + 1;
	
	int l_in = index(r, left);
	int u_in = index(up, c);
	int r_in = index(r, right);
	int d_in = index(down, c);
	
	marks[index(r, c)] = marker;
	
	if(left != -1 && marks[l_in] != marker && grids[l_in] == type)
		result += DFS(r, left, type);
	if(up != -1 && marks[u_in] != marker && grids[u_in] == type)
		result += DFS(up, c, type);
	if(right != columns && marks[r_in] != marker && grids[r_in] == type)
		result += DFS(r, right, type);
	if(down != rows && marks[d_in] != marker && grids[d_in] == type)
		result += DFS(down, c, type);
	
	if(r == rd && c == cd) 
		return 1;
	else 
		return result;
}

int BFS(int r, int c, char type, Quene *quene){
	ClearQuene(quene);
	//OK lets perform BFS
	int cur_index = index(r, c);
	int end = index(rd, cd);
	Enquene(quene, cur_index);
	while (Dequene(quene, &cur_index)) {
		//check if it is the destination
		if(cur_index == end) return 1;
		//if not, mark this one as 1
		marks[cur_index] = 1;
		
		int rc = cur_index / columns;
		int cc = cur_index % columns;
		//add its 4 children to the quene, but do check if it children is marked
		//left
		if(cc != 0){
			int temp_index = index(rc, cc - 1);
			if(grids[temp_index] == type && !marks[temp_index]){
				Enquene(quene, temp_index);
			}
		}
		//up
		if(rc != 0){
			int temp_index = index(rc - 1, cc);
			if(grids[temp_index] == type && !marks[temp_index]){
				Enquene(quene, temp_index);
			}
		}
		//right
		if(cc != columns - 1){
			int temp_index = index(rc, cc + 1);
			if(grids[temp_index] == type && !marks[temp_index]){
				Enquene(quene, temp_index);
			}
		}
		//down
		if(rc != rows - 1){
			int temp_index = index(rc + 1, cc);
			if(grids[temp_index] == type && !marks[temp_index]){
				Enquene(quene, temp_index);
			}
		}
	}
	
	return 0;
}

int index(int r, int c){
	return r * columns + c;
}