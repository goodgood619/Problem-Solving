#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
typedef pair <int, pair<int, int>> P;
queue <P> q;
int ans[1000];
char board[31][31][31];
bool visited[31][31][31];
int dist[31][31][31];
int goy[4] = { 0,1,-1,0 };
int goz[4] = { 1,0,0,-1 };
int updownx[2] = { 1,-1 };
int l, r, c, idx, idy, idz, enx, eny, enz, k;
void bfs(int x, int y, int z) {
	visited[x][y][z] = true;
	q.push({ x,{ y,z } });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second.first;
		int z = q.front().second.second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + goy[i];
			int nz = z + goz[i];
			if (ny<1 || ny>r || nz<1 || nz>c || visited[x][ny][nz] || board[x][ny][nz] == '#') continue;
			if (!visited[x][ny][nz]) {
				visited[x][ny][nz] = true;
				q.push({ x,{ ny,nz } });
				dist[x][ny][nz] = dist[x][y][z] + 1;
			}
		}
		for (int i = 0; i < 2; i++) {
			int nx = x + updownx[i];
			if (nx<1 || nx>l || visited[nx][y][z] || board[nx][y][z] == '#') continue;
			if (!visited[nx][y][z]) {
				visited[nx][y][z] = true;
				q.push({ nx,{ y,z } });
				dist[nx][y][z] = dist[x][y][z] + 1;
			}
		}
	}
}
int main() {
	while (1) {
		scanf("%d%d%d", &l, &r, &c);
		if (l == 0 && r == 0 && c == 0) break;
		memset(visited, false, sizeof(visited));
		memset(dist, 0, sizeof(dist));
		for (int i = 1; i <= l; i++) {
			for (int j = 1; j <= r; j++) {
				for (int k = 1; k <= c; k++) {
					scanf(" %c", &board[i][j][k]);
					if (board[i][j][k] == 'S') {
						idx = i;
						idy = j;
						idz = k;
					}
					else if (board[i][j][k] == 'E') {
						enx = i;
						eny = j;
						enz = k;
					}
				}
			}
		}
		bfs(idx, idy, idz);
		ans[k++] = dist[enx][eny][enz];
		if (ans[k-1] == 0)printf("Trapped!\n");
		else printf("Escaped in %d minute(s).\n", ans[k-1]);
	}
	return 0;
}