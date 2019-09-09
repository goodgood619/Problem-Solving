#include <stdio.h>
long long int dp[1010][1010] = { 0, };
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	dp[1][1] = 1;
	dp[1][2] = 1;
	dp[2][1] = 1;
	for (int i = 1; i <= n;i++)
	{
		dp[i][1] = 1;
	}
	for (int j = 1; j <= m; j++)
	{
		dp[1][j] = 1;
	}

	for (int i = 2;i <= n; i++)
	{
		for (int j=2; j <= m; j++)
			dp[i][j]=((dp[i - 1][j - 1] + dp[i][j - 1] + dp[i - 1][j]) % 1000000007);
	}
	printf("%d\n", dp[n][m]% 1000000007);
	return 0;
}