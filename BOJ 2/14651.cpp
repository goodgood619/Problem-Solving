#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
ll dp[40000];
int n;
#define mod 1000000009
int main() {
	scanf("%d", &n);
	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] * 3;
		dp[i] %= mod;
	}
	printf("%lld\n", dp[n]);
	return 0;
}