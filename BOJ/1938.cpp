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
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
int rx[8] = { 0,0,1,-1,1,1,-1,-1 };
int ry[8] = { 1,-1,0,0,1,-1,1,-1 };
int n,sx,sy,ex,ey,sdir,edir;
char board[55][55];
bool visited[55][55][2];
int dist[55][55][2];
// 0: 가로모양 , 1: 세로모양
// U,D,L,R,(T:한바퀴도는거)
// 중심점을 기준으로 향하면된다. 상,하,좌,우로 움직일수있는지, 그리고 돌릴수 있는지를 체크
void bfs(int x, int y, int dir) {
	queue<PP> q;
	q.push({ { x,y }, dir });
	visited[x][y][dir] = true;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dir = q.front().second;
		q.pop();
		bool rotate = true;
		for (int i = 0; i < 8; i++) {
			int nx = x + rx[i];
			int ny = y + ry[i];
			if (nx<1 || nx>n || ny<1 || ny>n || board[nx][ny] == '1') {
				rotate = false;
				break;
			}
		}
		if (rotate) {
			if (dir == 0) {
				if (!visited[x][y][1]) {
					visited[x][y][1] = true;
					q.push({ {x,y },1 });
					dist[x][y][1] = dist[x][y][0] + 1;
				}
				else {
					if (dist[x][y][1] > dist[x][y][0] + 1) {
						q.push({ { x,y },1 });
						dist[x][y][1] = dist[x][y][0] + 1;
					}
				}
			}
			else {
				if (!visited[x][y][0]) {
					visited[x][y][0] = true;
					q.push({ { x,y },0 });
					dist[x][y][0] = dist[x][y][1] + 1;
				}
				else {
					if (dist[x][y][0] > dist[x][y][1] + 1) {
						q.push({ { x,y },0 });
						dist[x][y][0] = dist[x][y][1] + 1;
					}
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx<1 || nx>n || ny<1 || ny>n || board[nx][ny] == '1') continue;
			if (dir == 0) { //가로
				if (ny - 1 < 1 || ny + 1 > n) continue; //양사이드체크
				if (board[nx][ny - 1] == '1' || board[nx][ny + 1] == '1') continue;
				if (!visited[nx][ny][0]) {
					visited[nx][ny][0] = true;
					q.push({ {nx,ny},0 });
					dist[nx][ny][0] = dist[x][y][0] + 1;
				}
				else {
					if (dist[nx][ny][0] > dist[x][y][0] + 1) {
						dist[nx][ny][0] = dist[x][y][0] + 1;
						q.push({ {nx,ny},0 });
					}
				}
			}
			else {
				if (nx - 1 < 1 || nx + 1 > n) continue; // 위아래체크
				if (board[nx - 1][ny] == '1' || board[nx + 1][ny] == '1') continue;
				if (!visited[nx][ny][1]) {
					visited[nx][ny][1] = true;
					q.push({ { nx,ny },1 });
					dist[nx][ny][1] = dist[x][y][1] + 1;
				}
				else {
					if (dist[nx][ny][1] > dist[x][y][1] + 1) {
						dist[nx][ny][1] = dist[x][y][1] + 1;
						q.push({ { nx,ny },1 });
					}
				}
			}
		}
	}

}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %c", &board[i][j]);
		}
	}
	vector<P> s, e;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (board[i][j] == 'B') {
				s.push_back({ i,j });
			}
			else if (board[i][j] == 'E') {
				e.push_back({ i,j });
			}
		}
	}
	sx = s[1].first;
	sy = s[1].second;
	if (s[1].second == s[2].second) sdir = 1;
	ex = e[1].first;
	ey = e[1].second;
	if (e[1].second == e[2].second) edir = 1;
	bfs(sx, sy, sdir);
	printf("%d\n", dist[ex][ey][edir]);
	return 0;
}