#include <cstdio>
#include <algorithm>
#include <cstdint>
using namespace std;
typedef int64_t ll;
int main() {
	int n,j,c;
	scanf("%d", &n);
	double a = 0, b = 0;
	scanf("%lf", &a);
	for (int i = 1; i < n; i++) {
		double num;
		scanf("%lf", &num);
		b += num;
	}
	scanf("%d%d", &j, &c);
	for (int i = 1; i <= c; i++) {
		double ta = a + j * a / (a + b);
		double tb = b + j * b / (a + b);
		a = ta, b = tb;
	}
	printf("%.9lf", a);
	return 0;
}