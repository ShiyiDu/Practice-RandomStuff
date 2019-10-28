#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000001

//typedef struct int{
//	int x;
//	int y;
//}int;

typedef struct Quene{
	int data[MAX_SIZE];
	int front;
	int rear;
}Quene;

//Create a quene
Quene InitQuene(){
	Quene *quene = malloc(sizeof(Quene));
	if(quene == NULL) {}
	quene->front = quene ->rear = 0;
	return *quene;
}

int IsEmpty(Quene *quene){
	return quene->front == quene->rear;
}

int Enquene(Quene *quene, int num){
	if((quene->rear+1) % MAX_SIZE == quene->front) return 0;
	quene->data[quene->rear] = num;
	quene->rear = (quene->rear + 1) % MAX_SIZE;
	return 1;
}

int Dequene(Quene *quene, int *num){
	if(quene->front == quene->rear) return 0;
	*num = (quene->data[quene->front]);
	quene->front = (quene->front + 1) % MAX_SIZE;
	return 1;
}

int ClearQuene(Quene *quene){
	quene->front = quene->rear = 0;
	return 1;
}

//////////////////////////////////////////////////
int search(int r, int c, char type, Quene *quene);
int index(int r, int c);

int rows, columns, rd, cd; char *grids, *marks;

int main(int argc, char *argv[]) {
	Quene quene = InitQuene();
	
	scanf("%d %d", &rows, &columns);
	grids = malloc(rows * columns * sizeof(short));
	marks = malloc(rows * columns * sizeof(short));
	
	for(int r = 0; r < rows; r++){
		char line[columns + 1];
		scanf("%s", line);
		for (int c = 0; c < columns; c++) {
			int ind = index(r, c);
			grids[ind] = line[c] - 48;
			marks[ind] = 0;
		}
	}
	
	int num_of_pairs = 0;
	scanf("%d", &num_of_pairs);
	
	char result[num_of_pairs];
	
	for(int i = 0; i < num_of_pairs; i++){
		for(int j = 0; j < rows * columns; j++){
			marks[j] = 0;
		}
		int r, c;
		scanf("%d %d %d %d", &r, &c, &rd, &cd);
		r--; c--; rd--; cd--;
		
		char type = grids[index(r, c)];
		if(type != grids[index(rd, cd)]) {
			result[i] = -1;
			continue;
		}
		if(search(r, c, type, &quene)){
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

int search(int r, int c, char type, Quene *quene){
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