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
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0};
int goy[4] = { 1,0,0,-1};
int n, m, k;
int dist[1003][1003][12][2];
bool visited[1003][1003][12];
int board[1003][1003];
int ans = 1e9;
void bfs(int x, int y) {
	queue <PPPP> q;
	q.push({ {x,y },{0,1 }});
	dist[x][y][0][1] = 1;
	visited[x][y][0] = true;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second.first;
		int flag = q.front().second.second;
		if (x == n && y == m) {
			ans = min(ans, dist[x][y][cnt][flag]);
			break;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx<1 || nx>n || ny<1 || ny>m ) continue;
			if (cnt < k) { //아직 부술수 있다
				if (flag == 0) { //밤일때
					if (board[nx][ny] == 1) {
						q.push({{x,y }, { cnt,(flag + 1) % 2 }});
						dist[x][y][cnt][(flag + 1) % 2] = dist[x][y][cnt][flag] + 1;
					}
					else {
						if (!visited[nx][ny][cnt]) {
							visited[nx][ny][cnt] = true;
							q.push({ { nx,ny },{ cnt,(flag + 1) % 2 } });
							dist[nx][ny][cnt][(flag + 1) % 2] = dist[x][y][cnt][flag] + 1;
						}
					}
				}
				else { //낮일때
					if (board[nx][ny] == 1) {
						if (!visited[nx][ny][cnt + 1]) {
							visited[nx][ny][cnt + 1] = true;
							q.push({ { nx,ny },{ cnt+1,(flag + 1) % 2 } });
							dist[nx][ny][cnt+1][(flag + 1) % 2] = dist[x][y][cnt][flag] + 1;
						}
					}
					else {
						if (!visited[nx][ny][cnt]) {
							visited[nx][ny][cnt] = true;
							q.push({ { nx,ny },{ cnt,(flag + 1) % 2 } });
							dist[nx][ny][cnt][(flag + 1) % 2] = dist[x][y][cnt][flag] + 1;
						}
					}
				}
			}
			else { //이제 부술수 없다
				if (board[nx][ny] == 1) continue;
				if (!visited[nx][ny][cnt]) { //벽이 아니면 낮과 밤이든 상관없이 이동가능
					visited[nx][ny][cnt] = true;
					q.push({ {nx,ny }, {cnt,(flag + 1) % 2}});
					dist[nx][ny][cnt][(flag+1)%2] = dist[x][y][cnt][flag] + 1;
				}
			}
		}
	}
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &board[i][j]);
		}
	}
	bfs(1, 1);
	ans == 1e9 ? printf("-1\n") : printf("%d\n", ans);
	return 0;
}