#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
double a, b,d;
int main() {
	scanf("%lf%lf%lf", &d, &a, &b);
	double p=sqrt((d*d) / (1 + ((b*b) / (a*a))));
	int q = (int)p;
	int r = (int)((p*b) / a);
	printf("%d %d\n", q, r);
	return 0;
}