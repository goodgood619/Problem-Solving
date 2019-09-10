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
#define mod 1000000007
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<double, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { -1,0,1,0 };
int goy[4] = { 0,1,0,-1 };
int t, Case = 1,n,m,ans;
int board[501][501];
bool visited[501][501];
void dfs(int x,int y,int sum,int cnt) {
	if (cnt == 4) {
		ans = max(ans, sum);
		return;
	}
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + gox[i], ny = y + goy[i];
		if (nx<1 || nx>n || ny<1 || ny>m || visited[nx][ny]) continue;
		dfs(nx, ny, sum + board[x][y], cnt + 1);
	}
	visited[x][y] = false;
}
void dfs2(int x,int y) {
	if (x + 1 <= n && y - 1 >= 1 && y + 1 <= m) ans = max(ans, board[x][y] + board[x + 1][y] + board[x][y - 1] + board[x][y + 1]);
	if (x + 1 <= n && y - 1 >= 1 && x - 1 >= 1)ans = max(ans, board[x][y] + board[x][y - 1] + board[x - 1][y] + board[x + 1][y]);
	if (x - 1 >= 1 && y - 1 >= 1 && y + 1 <= m)ans = max(ans, board[x][y] + board[x - 1][y] + board[x][y + 1] + board[x][y - 1]);
	if (x - 1 >= 1 && x + 1 <= n && y + 1 <= m)ans = max(ans, board[x][y] + board[x][y + 1] + board[x + 1][y] + board[x - 1][y]);
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %d", &board[i][j]);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dfs(i, j, 0, 0);
			dfs2(i, j);
		}
	}
	printf("%d\n", ans);
	return 0;
}