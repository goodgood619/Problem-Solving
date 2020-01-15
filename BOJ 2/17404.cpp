#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int color[1003][4];
int dp[1003][4];
int n;
int ans = 1e9;
int go(int n, int here,int first) {
	if (n == 1) {
		int cost = 1e9;
		if (here != first) cost = min(cost, color[1][here]);
		return cost;
	}
	int& ret = dp[n][here];
	if (ret != -1) return ret;
	ret = 1e9;
	for (int i = 1; i <= 3; i++) {
		if (here != i) {
			ret = min(ret, go(n - 1, i,first) + color[n][here]);
		}
	}
	return ret;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			scanf(" %d", &color[i][j]);
		}
	}
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= 3; i++) {
		memset(dp, -1, sizeof(dp));
		ans = min(ans, go(n, i,i));
	}
	printf("%d\n", ans);
	return 0;
}