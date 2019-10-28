#include <stdio.h>
#include <math.h>

#define maintain_fee 25000.0	
#define newcar_fee 6000000.0
#define sold_value 3000000.0

double SoldCost(int y);
double KeepCost(int y);
double SoldValue(int y);
double MaintainFee(int y);
double TotalMaintainFee(int y);

int main(int argc, char *argv[]) {
	for(int i = 1; i < 90; i++){
		double s = SoldCost(i);
		double k = KeepCost(i);
		
		printf("year: %d keep cost %.1hf, sold cost %.1hf, difference: %.1hf\n", i, k, s, s-k);
		
	}
}

double SoldCost(int y){
	double result = 0;
	result = KeepCost(y - 1) + newcar_fee + maintain_fee - SoldValue(y);
	return result;
}

//the keep cost of a specific year
double KeepCost(int y){
	double result = 0;
	result = newcar_fee + TotalMaintainFee(y);
	return result;
}

//the sold value of a specific year
double SoldValue(int y){
	double result = 0;
	result = round(sold_value * (pow(0.95, (float)y - 1)));
//	if(y > 36) return 10000;
	return result;
}

//the maintain fee of a specified year
double MaintainFee(int y){
	double result = 0;
	result = round(maintain_fee * (pow(1.1, (float)y - 1)));
	return result;
}

//total maintain fee including this year
double TotalMaintainFee(int y){
	double result = 0;
	for(int i = 1; i <= y; i++){
		result += MaintainFee(i);
	}
	return result;
}