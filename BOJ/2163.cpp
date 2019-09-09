#include <stdio.h>
#include <algorithm>
int n, m;
int dp[301][301];
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		dp[1][i] = i - 1;
	}
	for (int i = 1; i <= n; i++) {
		dp[i][1] = i - 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= m; j++) {
			dp[i][j] = dp[i][j - 1] + i;
		}
	}
	printf("%d\n", dp[n][m]);
	return 0;
}