#include <stdio.h>
#include <algorithm>
using namespace std;
long long dp[210][210];
int n, k;
int index;
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		dp[1][i] = 1;
	for (int i = 1; i <= k; i++)
		dp[i][1] = i;
	for (int i = 2; i <= k; i++) {
		index = i;
		for (int j = 2; j <= n; j++) {
			dp[i][j] = dp[i][j - 1]%1000000000;
			while(i>= 1)
			{
				if (i == 0)
					break;
				dp[index][j]=(dp[index][j]+dp[i - 1][j - 1])%1000000000;
				i--;
			}
			i = index;
		}
	}

	printf("%d\n", dp[k][n]);
	return 0;
}
