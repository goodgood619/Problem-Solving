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
typedef pair<int,pair<int, int>> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
int n,m, sx, sy, ex, ey;
char board[105][105];
int dist[105][105][3];
bool visited[105][105];
map<P,int> mm;
// 0:동 1:서 2:남 3:북
// 0->(2,3) 1->(2,3) 2:(0,1) 3:(0,1)
void dijk(int x,int y,int num) {
	// dist[x][y]: (x,y)까지 오는데 있어서 부순문의 최소갯수
	int ans = 0;
	priority_queue<PP, vector<PP>, greater<PP>> pq;
	memset(visited, false, sizeof(visited));
	for (int i = 0; i <= n+1; i++) {
		for (int j = 0; j <= m+1; j++) {
			dist[i][j][num] = 1e9;
		}
	}
	pq.push({ 0,{x,y} });
	dist[x][y][num] = 0;
	visited[x][y] = true;
	while (!pq.empty()) {
		int cnt = pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();
		visited[x][y] = true;
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx<0 || nx>n+1 || ny<0 || ny>m+1 || board[nx][ny] == '*' || visited[nx][ny]) continue;
			int c = cnt + (board[nx][ny] == '#');
			if (dist[nx][ny][num] > c) {
				dist[nx][ny][num] = c;
				pq.push({ c,{nx,ny} });
			}
		}
	}
	
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		mm.clear();
		scanf("%d%d", &n, &m);
		memset(dist, 0, sizeof(dist));
		for (int i = 0; i <= 104; i++) {
			for (int j = 0; j <= 104; j++) {
				board[i][j] = '\0';
			}
		}
		sx = 0, sy = 0, ex = 0, ey = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				scanf(" %c", &board[i][j]);
				if (board[i][j] == '$') {
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


		dijk(sx, sy,0);
		dijk(ex, ey,1);
		dijk(0, 0, 2);
		int Min = 1e9;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (board[i][j] == '*') continue;
				if (board[i][j] == '#') {
					Min = min(Min, dist[i][j][0] + dist[i][j][1] + dist[i][j][2] - 2);
				}
				else {
					Min = min(Min, dist[i][j][0] + dist[i][j][1] + dist[i][j][2]);
				}
			}
		}
		printf("%d\n", Min);
	}
	
	return 0;
}