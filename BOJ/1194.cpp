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
int n, m,sx,sy,ex,ey;
char board[50][50];
bool visited[50][50][1 << 6];
int dist[50][50][1 << 6];
vector<P> en;
int bfs(int x, int y) {
	queue<PP> q;
	q.push({ {x,y}, 0 });
	visited[x][y][0] = true;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int earnkey = q.front().second;
		q.pop();
		for (int i = 0; i < en.size(); i++) {
			if (x == en[i].first && y == en[i].second) {
				return dist[x][y][earnkey];
			}
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny][earnkey] || board[nx][ny] == '#') continue;
			if (board[nx][ny] >= 'A' && board[nx][ny] <= 'F') { //문
				if (earnkey & (1 << (board[nx][ny] - 'A'))) {
					dist[nx][ny][earnkey] = dist[x][y][earnkey] + 1;
					visited[nx][ny][earnkey] = true;
					q.push({ { nx,ny },earnkey });
				}
			}
			else if (board[nx][ny] >= 'a' && board[nx][ny] <= 'f') { //열쇠
				int newkey = earnkey | (1 << (board[nx][ny] - 'a'));
				dist[nx][ny][newkey] = dist[x][y][earnkey] + 1;
				q.push({ { nx,ny }, newkey });
				visited[nx][ny][newkey] = true;
			}
			else { //평지
				dist[nx][ny][earnkey] = dist[x][y][earnkey] + 1;
				visited[nx][ny][earnkey] = true;
				q.push({ { nx,ny },earnkey });
			}
		}
	}
	return -1;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %c", &board[i][j]);
			if (board[i][j] == '0') sx = i, sy = j;
			if (board[i][j] == '1') en.push_back({ i,j });
		}
	}
	printf("%d\n", bfs(sx, sy));
	return 0;
}