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
typedef pair<pair<int, int>, int> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
int m, n, sx, sy, ex, ey;
char board[105][105];
int dist[105][105][4];
bool visited[105][105][4];
queue<PP> q;
// 0:동 1:서 2:남 3:북
// 0->(2,3) 1->(2,3) 2:(0,1) 3:(0,1)
void bfs() {
	// 미리 4방향을 넣고 시작하자
	// 현재방향:dir, 다음좌표의 방향:i 가 다르다면, 거울을 설치해야 한다
	for (int i = 0; i < 4; i++) {
		visited[sx][sy][i] = true;
	}
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dir = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx<1 || nx>n || ny<1 || ny>m || board[nx][ny] == '*') continue;
			if (!visited[nx][ny][i]) {
				if (i == dir) {
					visited[nx][ny][dir] = true;
					dist[nx][ny][dir] = dist[x][y][dir];
					q.push({ {nx,ny},dir });
				}
				else {
					if (dir == 0 || dir == 1) {
						if (i == 0 || i == 1) continue;
						visited[nx][ny][i] = true;
						dist[nx][ny][i] = dist[x][y][dir] + 1;
						q.push({ {nx,ny},i });
					}
					else {
						if (i == 2 || i == 3) continue;
						visited[nx][ny][i] = true;
						dist[nx][ny][i] = dist[x][y][dir] + 1;
						q.push({ {nx,ny},i });
					}
				}
			}
			else {
				if (i == dir) {
					if (dist[nx][ny][dir] > dist[x][y][dir]) {
						dist[nx][ny][dir] = dist[x][y][dir];
						q.push({ { nx,ny },dir });
					}
				}
				else {
					if (dir == 0 || dir == 1) {
						if (i == 0 || i == 1) continue;
						if (dist[nx][ny][i] > dist[x][y][dir] + 1) {
							dist[nx][ny][i] = dist[x][y][dir] + 1;
							q.push({ { nx,ny },i });
						}
					}
					else {
						if (i == 2 || i == 3) continue;
						if (dist[nx][ny][i] > dist[x][y][dir] + 1) {
							dist[nx][ny][i] = dist[x][y][dir] + 1;
							q.push({ { nx,ny },i });
						}
					}
				}
			}
		}
	}

}
int main() {
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &board[i][j]);
			if (board[i][j] == 'C') {
				if (sx == 0) {
					sx = i;
					sy = j;
				}
				else {
					ex = i;
					ey = j;
				}
			}
		}
	}
	for (int i = 0; i < 4; i++)
		q.push({ {sx,sy},i });
	bfs();
	int Min = 1e9;
	for (int i = 0; i < 4; i++) {
		if (dist[ex][ey][i] == 0) continue;
		Min = min(Min, dist[ex][ey][i]);
	}
	printf("%d\n", Min);
	return 0;
}