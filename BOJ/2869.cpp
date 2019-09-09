#include <stdio.h>
#include <algorithm>
using namespace std;
double A, B, V;
int main(){
	scanf("%lf%lf%lf", &A, &B, &V);
	double day = 0;
	day = (V - A) / (A - B);
	double sk = day - (int)day;
	if (sk != 0) {
		int n = (int)day;
		n += 2;
		printf("%d\n", n);
	}
	else {
		int n = (int)day;
		n += 1;
		printf("%d\n", n);
	}
	return 0;
}