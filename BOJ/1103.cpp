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
using namespace std;
typedef long long ll;
#define INF 1000000000
typedef pair<int, int> P;
typedef pair<int, pair<int, int>> PP;
typedef pair<double, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
char board[55][55];
int dp[55][55];
int n, m;
bool visited[55][55];
int dfs(int x, int y) {

	if (visited[x][y]) {
		printf("-1\n");
		exit(0);
	}
	int &ret = dp[x][y];
	if (ret != -1) return ret;
	ret = 0;
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int jump=board[x][y]-'0';
		int nx = x + jump*gox[i];
		int ny = y + jump*goy[i];
		if (nx<1 || nx>n || ny<1 || ny>m || board[nx][ny]=='H') continue;
		ret=max(ret,dfs(nx, ny)+1);
	}
	visited[x][y] = false;
	return ret;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &board[i][j]);
		}
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", dfs(1, 1)+1);
	return 0;
}