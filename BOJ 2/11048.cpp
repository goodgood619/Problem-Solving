#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
int dp[1001][1001];
int n, m;
int board[1001][1001];
int go(int x, int y) {
	if (x<1 || x>n || y<1 || y>m) return 0;
	int &ret = dp[x][y];
	if (ret != -1) return dp[x][y];
	dp[x][y]=board[x][y];
	dp[x][y]+=max(go(x + 1, y), max(go(x, y + 1),go(x + 1, y + 1)));
	return dp[x][y];
}
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %d", &board[i][j]);
		}
	}
	memset(dp, -1, sizeof(dp));
	go(1, 1);
	printf("%d\n", dp[1][1]);
	return 0;
}