#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef pair <int, int> P;
queue <P> q;
char board[101][101];
int n, m;
int cnt = 1;
int gox[4] = { 0,1,0,-1 };
int goy[4] = { 1,0,-1,0 };
int Min = 99999999;
bool visited[101][101];
int dist[101][101];
void go(int x, int y) {
	visited[x][y] = true;
	q.push({ x,y });
	dist[x][y] = 1;
	while (!q.empty()) {
		int x=q.front().first;
		int y = q.front().second;
		q.pop();
		if (x == n && y == m) {
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx<1 || nx>n || ny<1 || ny>m || visited[nx][ny] || board[nx][ny] == '0') continue;
			if (!visited[nx][ny] && board[nx][ny] == '1') {
				visited[nx][ny] = true;
				q.push({ nx,ny });
				dist[nx][ny] = dist[x][y] + 1;
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &board[i][j]);
		}
	}
	go(1, 1);
	printf("%d\n", dist[n][m]);
	return 0;
}