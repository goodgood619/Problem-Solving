#include <stdio.h>
#include <algorithm>
using namespace std;
int t,n;
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int hab = 0;
		double average = 0;
		for (int i = 1; i <= n; i++) {
			int a;
			double d;
			scanf("%d%lf", &a, &d);
			hab += a;
			average += (a*d);
		}
		printf("%d %.1lf\n", hab, average /hab);
	}
	return 0;
}