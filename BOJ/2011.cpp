#include<stdio.h>
#include<string.h>
#define mod 1000000
int dp[5010];
char n[5010];
int main()
{
	scanf("%s", n + 1);
	int len = strlen(n + 1);
	int g = n[1] - '0';
	dp[0] = 1;
	if (g >=1 && g <= 9)
		dp[1] = 1;
	else
		dp[1] = 0;

	for (int i = 2; i <= len; i++)
	{
		int x = n[i] - '0';
		if (x >= 1 && x <= 9)
			dp[i] = (dp[i] + dp[i - 1]) % mod;
		if (i == 1) continue;
		if (n[i - 1] == '0') continue;
		int y = (n[i - 1] - '0') * 10 + (n[i] - '0');
		if (y >= 10 && y <= 26)
			dp[i] = (dp[i] + dp[i - 2]) % mod;
	}
	printf("%d\n", dp[len]);
	return 0;
}