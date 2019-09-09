#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;
long long Max, Min;
long long n, p, q;
int idx;
long long ans1;
typedef long long good;
map<good, good> dp2;
good go(long long n) {
	if (n == 0) return 1;
	if (dp2[n]) return dp2[n];
	return dp2[n] = go(n / p) + go(n / q);
}
int main() {
	dp2[0] = 1;
scanf("%lld%lld%lld", &n, &p, &q);
long long ans = go(n);
printf("%lld\n", ans);
return 0;
}