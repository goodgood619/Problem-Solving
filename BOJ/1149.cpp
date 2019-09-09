#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int color[1003][4];
int dp[1003][4];
int n;
#define INF 99999999
int ans = 999999999;
int go(int n, int here){
	if (n == 1) return color[1][here];
	int &ret = dp[n][here];
	if (ret != -1) return ret;
	ret = INF;
	for (int i = 1; i <= 3; i++) {
		if (here != i) {
			ret = min(ret, go(n - 1, i) + color[n][here]);
		}
	}
	return ret;
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			scanf(" %d", &color[i][j]);
		}
	}
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= 3; i++){
		memset(dp, -1, sizeof(dp));
		ans = min(ans, go(n,i));
	}
	printf("%d\n", ans);
	return 0;
}