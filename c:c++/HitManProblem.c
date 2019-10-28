#include <stdio.h>
#include <math.h>
double Value(int s, int m, int n);
double hit(int n, int s);
double snitch(int m, int s);
double run(int n, int m);

//static int ns[70], ms[70];
static double value[70];
int main(int argc, char *argv[]) {
	int m = 0, n = 0;
//	ns[69] = 0; ms[69] = 0;
	
	value[69] = 100000.0;
	for(int i = 68; i >= 0; i--){
		double v = Value(i, m, n);
		value[i] = v;
		if(v == hit(n + 1,i)){
			n++;
			printf("hit: %.2f\n", v);
		}else if(v == snitch(m + 1,i)){
			m++;
			printf("snitch: %.2f\n", v);
		}else{
			printf("run: %.2f\n", v);
			break;
		}
	}
}

double Value(int s, int m, int n){
//	if(s == 69) return 100000.0;
	double result = fmax(hit(n+1, s), fmax(snitch(m+1, s), run(n, m)));
	return result;
}

double hit(int n, int s){
	if(n == 20) return -1;
	return 50000.0*((20.0-n)/20.0)-(n/20.0)*value[s+1] + value[s+1];
}

double snitch(int m, int s){
	if(m == 50) return -1;
	return 35000.0 * ((50.0-m)/50.0) - (m/50.0) * value[s+1] + value[s+1];
}

double run(int n, int m){
	return -225000.0 + 100000.0 + 50000.0 * (n) + 35000.0*(m);
}