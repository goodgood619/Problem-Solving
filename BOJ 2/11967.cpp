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
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 1, 0,0,-1 };
int goy[4] = { 0, 1,-1,0 };
int n, m;
int board[105][105];
bool visited[105][105];
bool on[105][105];
vector<P> light[105][105];
void dfs(int x, int y) {
	if (visited[x][y]) return;
	visited[x][y] = true;
	for (int i = 0; i < light[x][y].size(); i++) {
		P next = light[x][y][i];
		if (!on[next.first][next.second]) {
			on[next.first][next.second] = true;
			for (int i = 0; i < 4; i++) {
				int nx = next.first + gox[i];
				int ny = next.second + goy[i];
				if (nx<1 || nx>n || ny<1 || ny>n || !on[nx][ny] || !visited[nx][ny]) continue;
				dfs(next.first, next.second);
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + gox[i];
		int ny = y + goy[i];
		if (nx<1 || nx>n || ny<1 || ny>n || !on[nx][ny]) continue;
		dfs(nx, ny);
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		light[a][b].push_back({ c,d });
	}
	on[1][1] = true;
	dfs(1, 1);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (on[i][j]) ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}