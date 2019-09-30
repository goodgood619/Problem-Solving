#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <list>
#include <climits>
#include <string.h>
#include <deque>
#include <functional>
#include <stack>
using namespace std;
typedef long long ll;
#define INF 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[3] = { -1,0,1 };
using namespace std;
int go(int ***dp,int x, int y, int dir, int** board, int n, int m) {
	if (x == n + 1) return 0;
	int& ret = dp[x][y][dir];
	if (ret != -1) return ret;
	ret = 1e9;
	for (int i = 0; i < 3; i++) {
		if (dir != i && y + goy[i] >= 1 && y + goy[i] <= m) ret = min(ret, go(dp,x + 1, y + goy[i], i, board, n, m) + board[x][y]);
	}
	return ret;

}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int** board = new int* [n + 1];
	int*** dp = new int**[n + 1];
	for (int i = 1; i <= n; i++) {
		board[i] = new int[m + 1];
	}

	for (int i = 1; i <= n; i++) {
		dp[i] = new int* [m + 1];
		for (int j = 1; j <=m; j++) {
			dp[i][j] = new int[3];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %d", &board[i][j]);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 0; k < 3; k++) {
				dp[i][j][k] = -1;
			}
		}
	}
	int ans = 1e9;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < 3; j++) {
			ans = min(ans, go(dp,1, i, j, board, n, m));
		}
	}
	printf("%d\n", ans);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			delete[] dp[i][j];
		}
	}
	for (int i = 1; i <= n; i++) delete[] dp[i];
	delete[] dp;

	for (int i = 1; i <= n; i++) delete[] board[i];
	delete[] board;
	return 0;
}