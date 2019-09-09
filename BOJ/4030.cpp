#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
int a, b,cnt;
int idx = 1;
int idx2 = 1;
int k;
int main() {
	double d;
	while (1) {
		scanf("%d%d", &a, &b);
		if (a == 0 && b == 0) break;
		for (int i = 1; (i*(i+1)) / 2 + 1 < b;i++) {
			k = (i*(i+1)) / 2 + 1;
			if (k <= a || k >= b) continue;
			d= k;
			if (sqrt(k)-(int)(sqrt(d))==0)
				cnt++;
			else
				continue;

		}
		printf("Case %d: %d\n", idx, cnt);
		idx++;
		cnt = 0;
	}
	return 0;
}