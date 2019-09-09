#include <cstdio>
#include <algorithm>
using namespace std;
int coin[101];
int dp[10001];
int n, k;
int main(){
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) { scanf("%d", &coin[i]);}
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j >= coin[i]) {
				dp[j] += dp[j - coin[i]];
			}
		}
	}
	printf("%d\n", dp[k]);
	return 0;
}