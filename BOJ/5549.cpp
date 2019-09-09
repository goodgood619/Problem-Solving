#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int dp[1030][1030][3]; //0은 정글, 1은 바다, 2는 얼음
char board[1030][1030];
int n, m,k;
int go(int x, int y,int k) {
	int &ret = dp[x][y][k];
	if (x <= 0 || y <= 0) return ret=0;
	if (ret != -1) return ret;
	ret = 0;
	int cnt = 0;
	if (board[x][y] == 'J' && k == 0) cnt = 1;
	else if (board[x][y] == 'O' && k == 1) cnt = 1;
	else if (board[x][y] == 'I' && k == 2) cnt = 1;
	ret = cnt+ go(x - 1, y,k)  + go(x, y - 1,k) - go(x - 1, y - 1,k);
	return ret;
}
int main() {
	scanf("%d%d", &n, &m);
	scanf("%d", &k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &board[i][j]);
		}
	}
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < 3; i++){
		go(n, m, i);
	}
	for (int i = 1; i <= k; i++){
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		int ans1 = dp[x2][y2][0] - dp[x2][y1-1][0] - dp[x1-1][y2][0] + dp[x1-1][y1-1][0];
		int ans2 = dp[x2][y2][1] - dp[x2][y1 - 1][1] - dp[x1 - 1][y2][1] + dp[x1 - 1][y1 - 1][1];
		int ans3 = dp[x2][y2][2] - dp[x2][y1 - 1][2] - dp[x1 - 1][y2][2] + dp[x1 - 1][y1 - 1][2];
		printf("%d %d %d\n", ans1,ans2,ans3);
	}
	return 0;
}