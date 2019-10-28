#include <stdio.h>

void setTriple(float a, float b, float c, float *x, float *y, float *z);
void addTriple(float a, float b, float c, float *x, float *y, float *z);

/* name: Shiyi Du, student number: 214438469 */
int main(int argc, char *argv[])
{
	float x, y, z;
	setTriple(1, 2, 3, &x, &y, &z);
	addTriple(4, 5, 6, &x, &y, &z);
	addTriple(x, y, z, &x, &y, &z);
	
	printf("x: %f, y:%f, z:%f \n", x, y, z);
	
	return 0;
}

void setTriple(float a, float b, float c, float *x, float *y, float *z)
{
	*x = a;
	*y = b;
	*z = c;
}

void addTriple(float a, float b, float c, float *x, float *y, float *z)
{
	*x += a;
	*y += b;
	*z += c;
}