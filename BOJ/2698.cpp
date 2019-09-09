#include <stdio.h>
#include <algorithm>
using namespace std;
int t, n, k;
long long dp[110][110][2];
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &k);
		dp[1][0][0] = 1;
		dp[1][1][1] = 1;
		dp[2][0][0] = 2;
		dp[2][0][1] = 1;
		dp[2][1][0] = 0;
		dp[2][1][1] = 1;
			for (int i = 3; i <= n; i++) {
				for (int j =0; j < i; j++) {
					dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
					dp[i][j][1] = dp[i - 1][j][0] + dp[i - 1][j - 1][1];
				}
			}
			printf("%lld\n", dp[n][k][0] + dp[n][k][1]);
	}

	return 0;
}