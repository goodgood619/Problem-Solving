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
int gox[5] = { 0,0,0,1,-1 };
int goy[5] = { 0,1,-1,0,0 };
int n, m,sx,sy,sdir,ex,ey,edir;
int dist[105][105][5];
bool visited[105][105][5];
int board[105][105];
void bfs(int x, int y, int dir) {
	queue<PP> q;
	q.push({ {x,y }, dir });
	visited[x][y][dir] = true;
	// 같은 위치, 같은방향을 또방문해도, 그 값이 최솟값이 아닐 가능성이 있다 ㅇㅇ
	// 왜냐하면, 
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dir = q.front().second;
		q.pop();
		int length = 0;
		for (int i = 1; i <= 3; i++) {
			int nx = x + i*gox[dir];
			int ny = y + i*goy[dir];
			if (nx < 1 || nx>n || ny<1 || ny>m) {
				break;
			}
			if (board[nx][ny] != 1) {
				length = i;
				continue;
			}
			else {
				break;
			}
		}

		for (int i = 1; i <= length; i++) { // 우선 dir방향으로 이동을하자
			int nx = x + i * gox[dir];
			int ny = y + i * goy[dir];
			if (!visited[nx][ny][dir]) {
				visited[nx][ny][dir] = true;
				dist[nx][ny][dir] = dist[x][y][dir] + 1;
				q.push({ {nx,ny }, dir });
			}
		}

		if (dir == 1) { //동쪽일때(남쪽과 북쪽은 1, 서쪽은 2)
			for (int i = 1; i <= 4; i++) {
				if(i==dir) continue;
				else if (i == 2) {
					if (!visited[x][y][i]) {
						visited[x][y][i] = true;
						dist[x][y][i] = dist[x][y][dir] + 2;
						q.push({ {x,y },i });
					}
				}
				else if(i==3 || i==4){
					if (!visited[x][y][i]) {
						visited[x][y][i] = true;
						dist[x][y][i] = dist[x][y][dir] + 1;
						q.push({ {x,y },i });
					}
				}
			}
		}
		else if (dir == 2) { //서쪽일때(남쪽과 북쪽은 1, 동쪽은 2)
			for (int i = 1; i <= 4; i++) {
				if(i == dir) continue;
				else if (i == 1) {
					if (!visited[x][y][i]) {
						visited[x][y][i] = true;
						dist[x][y][i] = dist[x][y][dir] + 2;
						q.push({ {x,y },i });
					}
				}
				else if (i == 3 || i == 4) {
					if (!visited[x][y][i]) {
						visited[x][y][i] = true;
						dist[x][y][i] = dist[x][y][dir] + 1;
						q.push({ {x,y },i });
					}
				}
			}

		}
		else if (dir == 3) { //남쪽일때(서쪽과 동쪽은 1,북쪽은 2)
			for (int i = 1; i <= 4; i++) {
				if(i == dir) continue;
				else if (i == 4) {
					if (!visited[x][y][i]) {
						visited[x][y][i] = true;
						dist[x][y][i] = dist[x][y][dir] + 2;
						q.push({ {x,y },i });
					}
				}
				else if (i == 1 || i == 2) {
					if (!visited[x][y][i]) {
						visited[x][y][i] = true;
						dist[x][y][i] = dist[x][y][dir] + 1;
						q.push({ {x,y },i });
					}
				}
			}
		}
		else { //북쪽일때(서쪽과 동쪽은 1,남쪽은 2)
			for (int i = 1; i <= 4; i++) {
				if( i == dir) continue;
				else if (i == 3) {
					if (!visited[x][y][i]) {
						visited[x][y][i] = true;
						dist[x][y][i] = dist[x][y][dir] + 2;
						q.push({ {x,y },i });
					}
				}
				else if (i == 1 || i == 2) {
					if (!visited[x][y][i]) {
						visited[x][y][i] = true;
						dist[x][y][i] = dist[x][y][dir] + 1;
						q.push({ {x,y },i });
					}
				}
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %d", &board[i][j]);
		}
	}
	scanf("%d%d%d", &sx, &sy, &sdir);
	scanf("%d%d%d", &ex, &ey, &edir);
	bfs(sx, sy, sdir);
	printf("%d\n", dist[ex][ey][edir]);
	return 0;
}