#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//TODO: This solution sometime produce unexpected result, probablly because the memory is being changed unexpectly?

typedef struct Point3{
	float x;
	float y;
	float z;
}Point3;

//float GetDistance(Point3 points[], Point3 *p3);
//float GetDistance(Point3 *p1, Point3 *p2, Point3 *p3);
double GetArea(Point3 points[], int size);
void GetPlane(Point3 p1,Point3 p2,Point3 p3,double *a,double *b,double *c,double *d);
double Distance2Plane(Point3 pt, Point3 points[]);
double GetTriangleArea(double a, double b, double c);
double GetVolume(Point3 points[], int verts[], int surface);

int main(int argc, char *argv[]) {
	
//	Point3 p0 = {0,0,0}, p1 = {1,0,0}, p2 = {1,0,1}, p3 = {0,0,1}, p4 = {1,1,1};
//	int num_of_verts = 16;
//	int faces[5] = {3,3,3,3,4};
//	Point3 all_verts[] = {p0, p4, p1,
//						p1, p2, p4,
//						p2, p3, p4,
//						p3, p0, p4,
//						p0, p1, p2, p3};
//						
//	double result = GetVolume(all_verts, faces, 5);
//	
//	printf("%f", result);
	
	int num_of_polys, num_of_faces, num_of_verts;
	double result = 0;
	scanf("%d", &num_of_polys);
	for(int i = 0; i < num_of_polys; i++){
		scanf("%d", &num_of_faces);
		
		int total_verts = 0;
		int face_verts[num_of_faces];
		Point3 *all_verts = malloc(72000 * sizeof(Point3));
		
		for(int j = 0; j < num_of_faces; j++){
			scanf("%d", &num_of_verts);
			face_verts[j] = num_of_verts; //this is indicating how much verts each face has
			for(int k = 0; k < num_of_verts; k++){
				scanf("%f %f %f", &(all_verts+k+total_verts)->x, &(all_verts+k+total_verts)->y, &(all_verts+k+total_verts)->z);
			}
			total_verts += num_of_verts;
		}
		
		result += GetVolume(all_verts, face_verts, num_of_faces);
	}
	
	printf("\n%.2f", result);
}

double GetVolume(Point3 points[], int verts[], int surface){
	double result, area, distance;
	int current_surface = 0;
	Point3 vertex = points[0];
	for(int i = 0; i < surface; i++){
		area = GetArea(&points[current_surface], verts[i]);
		distance = Distance2Plane(vertex, &points[current_surface]);
		current_surface += verts[i];
		result += area * distance / 3;
	}
	return result;
}

void GetPlane(Point3 p1,Point3 p2,Point3 p3,double *a,double *b,double *c,double *d){
	*a = ((p2.y-p1.y)*(p3.z-p1.z)-(p2.z-p1.z)*(p3.y-p1.y));
	*b = ((p2.z-p1.z)*(p3.x-p1.x)-(p2.x-p1.x)*(p3.z-p1.z));
	*c = ((p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x));  
	*d = (0-(*a*p1.x+*b*p1.y+*c*p1.z));  
}

//get the dictance from a point to a plane
double Distance2Plane(Point3 pt, Point3 points[]){
	double a, b, c, d;
	GetPlane(points[0], points[1], points[2], &a, &b, &c, &d);
	return fabs(a*pt.x+b*pt.y+c*pt.z+d)/sqrt(a*a+b*b+c*c);
}

//get the area of a triangle
double GetTriangleArea(double a, double b, double c){
	double p, result;
	p = (a + b + c) / 2;
	result = sqrt(p*(p-a)*(p-b)*(p-c));
	return result;
}

//get the area of a surface
double GetArea(Point3 points[], int size){
	Point3 vertex = points[0], p1, p2;
	double result = 0, v_p1, p1_p2, p2_v;
	for(int i = 1; i < size - 1; i++){
		p1 = points[i];
		p2 = points[i+1];
		
		v_p1 = sqrt(pow(vertex.x - p1.x, 2) + pow(vertex.y - p1.y, 2) + pow(vertex.z - p1.z, 2));
		p1_p2 = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) + pow(p1.z - p2.z, 2));
		p2_v = sqrt(pow(vertex.x - p2.x, 2) + pow(vertex.y - p2.y, 2) + pow(vertex.z - p2.z, 2));

		result += GetTriangleArea(v_p1, p1_p2, p2_v);
	}
	
	return result;
}

//float GetDistance(Point3 *p1, Point3 *p2, Point3 *p3){
//	float result, up, down;
//	
//	up = fabs((p3->x - p1->x)*(p1->y - p2->y) - (p1->x - p2->x) * (p3->y - p1->y));
//	down = sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2));
//	result = up/down;
//	return result;
//}

//float GetDistance(Point3 points[], Point3 *p3){
//	float result, up, down;
//	
//	Point3 *p1 = &points[0];
//	Point3 *p2 = &points[1];
//	
//	up = fabs((p3->x - p1->x)*(p1->y - p2->y) - (p1->x - p2->x) * (p3->y - p1->y));
//	down = sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2));
//	result = up/down;
//	return result;
//}
