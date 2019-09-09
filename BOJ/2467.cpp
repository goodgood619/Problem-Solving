#include <cstdio>
#include <algorithm>
#include <math.h>
using namespace std;
int water[100003];
int n;
typedef long long ll;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &water[i]);
	}
	int fptr = 1;
	int lptr = n;
	ll Min = 98765432111;
	ll ans1 = 0;
	ll ans2 = 0;
	while (1) {
		if (fptr > lptr) break;
		if (Min > abs(water[fptr] + water[lptr]) && fptr != lptr) {
			Min = abs(water[fptr] + water[lptr]);
			ans1 = water[fptr];
			ans2 = water[lptr];
		}

		if (water[fptr] + water[lptr]<0) {
			fptr++;
		}
		else if (water[fptr] + water[lptr]>0) {
			lptr--;
		}
		else if (water[fptr] + water[lptr] == 0) {
			ans1 = water[fptr];
			ans2 = water[lptr];
			break;
		}
	}
	if (ans1 > ans2) {
		ll t = ans1;
		ans1 = ans2;
		ans2 = t;
	}
	printf("%lld %lld\n", ans1, ans2);
	return 0;
}
