#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int dp[303][303];
int board[303][303];
int n, m,Max;
int go(int x, int y){
	if (x<1 || y<1 || x>n || y>m) return 0;
	int &ret = dp[x][y];
	if (ret != -1) return ret;
	return ret=max(go(x - 1, y)+board[x][y],go(x, y - 1)+board[x][y]);
}
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++){
		for (int j=1;j<=m;j++){
			scanf(" %d", &board[i][j]);
		}
	}
	memset(dp, -1, sizeof(dp));

	go(n, m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			Max=max(Max, dp[i][j]);
		}
	}
	printf("%d\n", Max);
	return 0;
}