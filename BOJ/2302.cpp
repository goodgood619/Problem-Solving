#include <stdio.h>
#include <algorithm>
using namespace std;
long long dp[100];
int arr[50];
int vip[50];
int n, m;
int cnt;
int cnt2;
int main() {
	scanf("%d", &n);
	scanf("%d", &m);
	if (m != 0)
	{
		for (int i = 1; i <= m; i++) {
			int u;
			scanf("%d", &u);
			vip[i] = u;
		}
		vip[0] = 1;
		vip[m + 1] = n;
		dp[0] = 1;
		dp[1] = 1;
		dp[2] = 2;
		long long Cnt = 1;
		for (int i = 3; i <= 50; i++)
			dp[i] = dp[i - 1] + dp[i - 2];
		Cnt *= dp[vip[1] - vip[0]];
		for (int i = 1; i <= m - 1; i++)
		{
			Cnt *= dp[vip[i + 1] - vip[i] - 1];
		}
		Cnt *= dp[vip[m + 1] - vip[m]];
		printf("%lld\n", Cnt);
	}
	else {
		dp[0] = 1;
		dp[1] = 1;
		dp[2] = 2;
		for (int i = 3; i <= 50; i++)
			dp[i] = dp[i - 1] + dp[i - 2];
		printf("%lld\n", dp[n]);
	}
	return 0;
}