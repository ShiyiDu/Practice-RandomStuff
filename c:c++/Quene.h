#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000001

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