#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
ll dp[105][105];
ll board[105][105];
int n;
ll go(int x, int y) {
	if (x > n || y > n) return 0;
	if (x == n && y == n) return 1;
	ll &ret = dp[x][y];
	if (ret != -1) return ret;
	ret = 0;
	ll jump = board[x][y];
	if (jump == 0) return 0;
	ret = go(x + jump, y) + go(x, y + jump);
	return ret;
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %lld", &board[i][j]);
		}
	}
	memset(dp, -1, sizeof(dp));
	printf("%lld\n", go(1, 1));
	return 0;
}