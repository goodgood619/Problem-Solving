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
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[6] = { -2,-2,0,0,2,2 };
int goy[6] = { -1,1,2,-2,-1,1 };
int n,sx,sy,ex,ey;
bool visited[205][205];
int dist[205][205];
int bfs(int x, int y) {
	queue<P> q;
	visited[x][y] = true;
	q.push({ x,y });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		if (x == ex && y == ey) return dist[x][y];
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (visited[nx][ny]) continue;
			if (!visited[nx][ny]) {
				visited[nx][ny] = true;
				q.push({ nx,ny });
				dist[nx][ny] = dist[x][y] + 1;
			}
		}
	}
	return -1;
}
int main() {
	scanf("%d", &n);
	scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
	int ans = bfs(sx, sy);
	if (ans == -1) printf("-1\n");
	else printf("%d\n", ans);
	return 0;
}