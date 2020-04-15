#include <cstdio>
#include <algorithm>
#include <cstdint>
using namespace std;
typedef int64_t ll;
#define mod 1000000007
ll go(int n) {
	if (n == 0) return 1;
	if (n % 2 == 0) {
		ll ret = go(n / 2);
		return ret * ret % mod;
	}
	else {
		ll ret = go((n - 1) / 2);
		return ret * ret * 2 % mod;
	}
}
int main() {
	int t;
	scanf("%d", &t);
	while (t-- > 0) {
		int n;
		scanf("%d", &n);
		if (n == 1) printf("1\n");
		else printf("%d\n", go(n - 2));
	}
	return 0;
}