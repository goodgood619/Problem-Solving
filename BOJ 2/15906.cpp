#include <cstdio>
#include <algorithm>
#include <cstdint>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
typedef int64_t ll;
struct P {
	int x, y;
	bool mode;
};
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int find(int x, int y, int dir, vector<vector<char>>& board, int n) {
	int cnt = 0;
	while (x + gox[dir] < n && x + gox[dir] >= 0 && y + goy[dir] < n && y + goy[dir] >= 0) {
		x += gox[dir];
		y += goy[dir];
		cnt++;
		if (board[x][y] == '#') break;
	}
	if (board[x][y] == '#') return cnt;
	else return 0;
}
void bfs(int sx, int sy, int ex, int ey, vector<vector<char>>& board, int n, int t) {
	queue<P> q;
	q.push({ sx,sy,false });
	vector<vector<vector<bool>>> visited;
	vector<vector<vector<int>>> dist;
	visited.assign(n, vector<vector<bool>>(n, vector<bool>(2, false)));
	dist.assign(n, vector<vector<int>>(n, vector<int>(2, 0)));
	visited[sx][sy][0] = true;
	int ans = 1e9;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		bool mode = q.front().mode;
		q.pop();
		if (x == ex && y == ey) {
			if (mode) ans = min(ans, dist[x][y][1]);
			else ans = min(ans, dist[x][y][0]);
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i], ny = y + goy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			//일반모드, t턴을 소모하고서 변신을 하고 그 위치로 이동, 그냥 이동하던가
			if (!mode) {
				int gateDist = find(x, y, i, board, n);
				if (gateDist != 0) {
					int nx2 = x + gateDist * gox[i], ny2 = y + gateDist * goy[i];
					if (!visited[nx2][ny2][1]) {
						visited[nx2][ny2][1] = true;
						dist[nx2][ny2][1] = dist[x][y][0] + t + 1;
						q.push({ nx2, ny2, true });
					}
					else if (dist[nx2][ny2][1] > dist[x][y][0] + t + 1) {
						dist[nx2][ny2][1] = dist[x][y][0] + t + 1;
						q.push({ nx2, ny2, true });
					}
				}
				if (!visited[nx][ny][0]) {
					visited[nx][ny][0] = true;
					dist[nx][ny][0] = dist[x][y][0] + 1;
					q.push({ nx, ny, false });
				}
				else if (dist[nx][ny][0] > dist[x][y][0] + 1) {
					dist[nx][ny][0] = dist[x][y][0] + 1;
					q.push({ nx, ny, false });
				}
			}
			// 변신모드, 가장 가까운 게이트웨이를 찾으면 변신모드 유지하면서 넣어주고, 그냥 일반모드로 돌아갈수도 있으니 그냥 이동
			else {
				int gateDist = find(x, y, i, board, n);
				if (gateDist != 0) {
					int nx2 = x + gateDist * gox[i], ny2 = y + gateDist * goy[i];
					if (!visited[nx2][ny2][1]) {
						visited[nx2][ny2][1] = true;
						dist[nx2][ny2][1] = dist[x][y][1] + 1;
						q.push({ nx2, ny2, true });
					}
					else if (dist[nx2][ny2][1] > dist[x][y][1] + 1) {
						dist[nx2][ny2][1] = dist[x][y][1] + 1;
						q.push({ nx2, ny2, true });
					}
				}
				// 일반모드 복귀
				if (!visited[nx][ny][0]) {
					visited[nx][ny][0] = true;
					dist[nx][ny][0] = dist[x][y][1] + 1;
					q.push({ nx, ny, false });
				}
				else if (dist[nx][ny][0] > dist[x][y][1] + 1) {
					dist[nx][ny][0] = dist[x][y][1] + 1;
					q.push({ nx, ny, false });
				}
			}
		}
	}
	printf("%d\n", ans);
	visited.clear();
	dist.clear();
}
int main() {
	int n, t, r, c;
	scanf("%d%d%d%d", &n, &t, &r, &c);
	r--, c--;
	vector<vector<char>> board;
	board.assign(n, vector<char>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %c", &board[i][j]);
		}
	}
	bfs(0, 0, r, c, board, n, t);
	board.clear();
	return 0;
}