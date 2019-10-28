#include <stdio.h>
#include <stdlib.h>

int search(int r, int c);
int index(int r, int c);

int rows, columns, rd, cd; char *grids;
short *marks, current_marker;
char current_type;

int main(int argc, char *argv[]) {
	scanf("%d %d", &rows, &columns);
	grids = malloc(rows * columns * sizeof(short));
	marks = malloc(rows * columns * sizeof(short));
	
	for(int r = 0; r < rows; r++){
		char line[columns + 1];
		scanf("%s", line);
		for (int c = 0; c < columns; c++) {
			int ind = index(r, c);
			grids[ind] = line[c] - 48;
			marks[ind] = -1;
		}
	}
	
	int num_of_pairs = 0;
	scanf("%d", &num_of_pairs);
	
	char result[num_of_pairs];
	
	for(int i = 0; i < num_of_pairs; i++){
		int r, c;
		scanf("%d %d %d %d", &r, &c, &rd, &cd);
		r--; c--; rd--; cd--;
		
		char type = grids[index(r, c)];
		if(type != grids[index(rd, cd)]) {
			result[i] = -1;
			continue;
		}
		current_type = type;
		current_marker = i;
		int start_index = index(r, c);
		int end_index = index(rd, cd);
		//mark all the visited nodes in the same land with a uniq marker
		//so next time if you get two nodes with the same marker, you know 
		//they are on the same land and there is a path between them!
		if(marks[start_index] != -1){
			if(marks[start_index] == marks[end_index]){
				result[i] = type;
			}else {
				result[i] = -1;
			}
		}else if(search(r, c)){
			result[i] = type;
		}else {
			result[i] = -1;
		}
	}
	
	for(int i = 0; i < num_of_pairs; i++){
		switch (result[i]) {
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

//-1 means searched

//return 0 if no path, 1 if path found
int search(int r, int c){
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
	
	marks[index(r, c)] = current_marker;
	
	if(left != -1 && marks[l_in] != current_marker && grids[l_in] == current_type)
		result += search(r, left);
	if(up != -1 && marks[u_in] != current_marker && grids[u_in] == current_type)
		result += search(up, c);
	if(right != columns && marks[r_in] != current_marker && grids[r_in] == current_type)
		result += search(r, right);
	if(down != rows && marks[d_in] != current_marker && grids[d_in] == current_type)
		result += search(down, c);
	
	if(r == rd && c == cd) 
		return 1;
	else 
		return result;
}

int index(int r, int c){
	return r * columns + c;
}


