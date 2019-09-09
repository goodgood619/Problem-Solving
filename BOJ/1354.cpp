#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
ll n, p, q, x, y;
map<ll, ll> dp;
ll go(long long n) {
	if (n <= 0) return 1;
	if (dp[n]) return dp[n];
	return dp[n] = go(n / p - x) + go(n / q - y);
}
int main() {
	scanf("%lld%lld%lld%lld%lld", &n, &p, &q, &x, &y);
	long long ans = go(n);
	printf("%lld\n", ans);
	return 0;
}
