#include <stdio.h>
#include <algorithm>
using namespace std;
int gox[3] = { -1,0,1 };
char board[10001][501];
bool visited[10001][501];
int n, m,cnt;
bool ok,check;
void dfs(int x, int y) {
	visited[x][y] = true;
	if (ok) return;
	if (y == m) {
		ok = true;
			return;
		}
	for (int i = 0; i < 3; i++) {
		int nx = x + gox[i];
		if (nx<1 || nx>n || y + 1 < 1 || y + 1 > m || visited[nx][y + 1] || board[nx][y + 1] == 'x') continue;
		if (!visited[nx][y + 1] && !ok) {
			dfs(nx, y + 1);
			//if (!ok) visited[nx][y + 1] = false;
		}
	}
	return;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &board[i][j]);
			if (board[i][j] == 'x') visited[i][j] = true;
		}
	}
	for (int i = 1; i <= n; i++){
		if (!visited[i][1]) {
			dfs(i, 1);
			if (ok) cnt++;
		}
		ok = false;
	}
	printf("%d\n", cnt);
	return 0;
}