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
int goy[4] = { 1,0,0,-1 };
int n, m;
int board[1026][1026];
int dp[1026][1026];
int go(int x, int y) {
	if (x <= 0 || y <= 0) return 0;
	int &ret = dp[x][y];
	if (ret != -1) return ret;
	ret = 0;
	ret = board[x][y] + go(x - 1, y) + go(x, y - 1) - go(x - 1, y - 1);
	return ret;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %d", &board[i][j]);
		}
	}
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) dp[i][0] = 0;
	for (int i = 1; i <= n; i++) dp[0][i] = 0;
	go(n, n);

	for (int i = 1; i <= m; i++) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		printf("%d\n", dp[x2][y2] - dp[x2][y1-1] - dp[x1-1][y2] + dp[x1-1][y1-1]);
	}

	return 0;

}