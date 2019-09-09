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
int gox[4] = { 0,1,-1,0};
int goy[4] = { 1,0,0,-1};
int n, m, k;
int dist[1003][1003][3];
bool visited[1003][1003][3];
int board[1003][1003];
int ans = 1e9;
void bfs(int x, int y) {
	queue <PP> q;
	q.push({ {x,y },0 });
	dist[x][y][0] = 1;
	visited[x][y][0] = true;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		if (x == n && y == m) {
			ans = min(ans, dist[x][y][cnt]);
			break;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx<1 || nx>n || ny<1 || ny>m ) continue;
			if (cnt < 1) { //아직 부술수 있다
				if (board[nx][ny] == 0) {
					if (!visited[nx][ny][cnt]) {
						visited[nx][ny][cnt] = true;
						q.push({ {nx,ny }, cnt });
						dist[nx][ny][cnt] = dist[x][y][cnt] + 1;
					}
				}
				else {
					if (!visited[nx][ny][cnt + 1]) {
						visited[nx][ny][cnt + 1] = true;
						q.push({ {nx,ny }, cnt + 1 });
						dist[nx][ny][cnt + 1] = dist[x][y][cnt] + 1;
					}
				}
			}
			else { //이제 부술수 없다
				if (board[nx][ny] == 1) continue;
				if (!visited[nx][ny][cnt]) {
					visited[nx][ny][cnt] = true;
					q.push({ {nx,ny }, cnt });
					dist[nx][ny][cnt] = dist[x][y][cnt] + 1;
				}
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &board[i][j]);
		}
	}
	bfs(1, 1);
	ans == 1e9 ? printf("-1\n") : printf("%d\n", ans);
	return 0;
}