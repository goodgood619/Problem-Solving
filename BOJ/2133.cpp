#include <stdio.h>
int dp[31];
int main(void)
{
	int n;
	scanf("%d", &n);
	dp[0] = 1;
	for (int i = 2; i <= n; i += 2)
	{
		dp[i] = 3 * dp[i - 2];
		for (int j = 4; j <= i; j += 2)
			dp[i] += 2 * dp[i - j];
	}
	printf("%d", dp[n]);
}
