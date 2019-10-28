#include <stdio.h>
#define MAXNAME 100

typedef struct {
	char name[MAXNAME];
	int valid;
	int index;
	float age;
} *array_t;

int main(int argc, char *argv[]) {
//	array_t = malloc(5 * )
	
	printf("%d",sizeof(array_t));
}
