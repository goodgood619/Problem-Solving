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
typedef pair<int, pair<int, int>> PP;
typedef pair<pair<int, int>, pair<int,int>> PPP;
int gox[4] = {0,1,-1,0};
int goy[4] = {1,0,0,-1};
int dirx[8] = {-2,-1,1,2,-2,-1,1,2};
int diry[8] = {1,2,2,1,-1,-2,-2,-1};
int k, w, h,ans=-1;
int board[205][205];
bool visited[205][205][405];
void bfs(int x, int y) {
	queue<PPP> q;
	q.push({ {k,0},{x,y} });
	visited[x][y][0] = true;
	while (!q.empty()) {
		int cnt = q.front().first.first;
		int dist = q.front().first.second;
		int x = q.front().second.first;
		int y = q.front().second.second;
		if (x == h && y == w) {
			ans = dist;
			return;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx<1 || nx>h || ny<1 || ny>w ||board[nx][ny]==1 || visited[nx][ny][cnt]) continue;
			else {
				q.push({{cnt,dist + 1 }, { nx,ny }});
				visited[nx][ny][cnt] = true;
			}
		}
		if (cnt > 0) {
			for (int i = 0; i < 8; i++) {
				int nx = x + dirx[i];
				int ny = y + diry[i];
				if (nx<1 || nx>h || ny<1 || ny>w ||board[nx][ny]==1 || visited[nx][ny][cnt-1]) continue;
				else {
					q.push({{ cnt - 1,dist + 1 },{ nx,ny }});
					visited[nx][ny][cnt-1] = true;
				}
			}
		}
	}
}
int main() {
	scanf("%d%d%d", &k, &w, &h);
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			scanf(" %d", &board[i][j]);
		}
	}
	bfs(1, 1);
	printf("%d\n", ans);
	return 0;
}