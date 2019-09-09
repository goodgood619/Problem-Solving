#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
int cnt;
int dp[1000010];
int trace[1000010];
int coin[550];
void init(int Coin, int n) {
	if (Coin>n) return;
	coin[cnt++] = Coin;
	init(Coin * 10 + 4, n);
	init(Coin * 10 + 7, n);
}
int main()
{
	int n;
	scanf("%d", &n);
	init(0, n);
	sort(coin, coin + cnt);
	memset(dp, -1, sizeof(dp));

	dp[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j =1; j <cnt; j++) {
			if (i - coin[j] < 0 || dp[i - coin[j]] == -1)continue;
			if (dp[i] == -1 || dp[i] > dp[i - coin[j]] + 1) {
				dp[i] = dp[i - coin[j]] + 1;
				trace[i] = coin[j];
			}

		}
	}

	if (dp[n] == -1)
		printf("-1\n");
	else {
		while (n) {
			printf("%d ", trace[n]);
			n = n - trace[n];
			if (n<0)
				break;
		}
	}
	printf("\n");
	return 0;
}
