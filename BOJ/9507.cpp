#include <stdio.h>
#include <algorithm>
using namespace std;
long long dp[80];
int t,n;
int main() {
	scanf("%d", &t);
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= 69; i++)
		dp[i] = dp[i - 4] + dp[i - 3] + dp[i - 2] + dp[i - 1];
	while (t--) {
		scanf("%d",&n);
		printf("%lld\n", dp[n]);
	}
	return 0;
}