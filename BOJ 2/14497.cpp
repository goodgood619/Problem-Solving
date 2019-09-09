#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
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
#define mod 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n, m,sx,sy,ex,ey,ti;
char board[305][305];
bool visited[305][305];
void bfs() {
	queue<P> q;
	q.push({ sx,sy });
	visited[sx][sy] = true;
	while (1) {
		queue<P> temp;
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if (x == ex && y == ey) return;
			for (int i = 0; i < 4; i++) {
				int nx = x + gox[i];
				int ny = y + goy[i];
				if (nx<1 || nx>n || ny<1 || ny>m || visited[nx][ny]) continue;
				if (board[nx][ny] == '0') {
					q.push({ nx,ny });
					visited[nx][ny] = true;
				}
				else {
					temp.push({ nx,ny });
					visited[nx][ny] = true;
				}
			}
		}
		q = temp;
		ti++;
	}
}
int main() {
	scanf("%d%d", &n, &m);
	scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %1c", &board[i][j]);
		}
	}
	bfs();
	printf("%d\n", ti);
	return 0;
}