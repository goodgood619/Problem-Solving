#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
typedef int64_t ll;
ll go(long b, long p, long mod) {
	if (p == 0) return 1;
	if (p == 1) return b;
	else if (p % 2 == 0) {
		ll temp = go(b, p / 2, mod);
		return (temp % mod * temp % mod) % mod;
	}
	else {
		ll temp = go(b, (p - 1) / 2, mod);
		return (temp % mod * temp % mod) * b % mod;
	}
}
int main() {
	ll* fact = new ll[1000001];
	for (int i = 0; i <= 1000000; i++) fact[i] = 0;
	ll p = 1000000007;
	fact[0] = 1;
	fact[1] = 1;
	for (int i = 2; i <= 1000000; i++) {
		fact[i] = fact[i - 1] * i % p;
	}
	int n, k;
	scanf("%d%d", &n, &k);
	ll a = fact[n], b = fact[n - k] * fact[k] % p;
	ll temp = go(b, p - 2, p);
	printf("%lld\n", a % p * temp % p % p);
	return 0;
}