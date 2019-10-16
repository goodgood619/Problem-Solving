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
int gox[4] = {-1,1,0,0 };
int goy[4] = {0,0,-1,1 };
int T, n,sum,sx,sy,ex,ey;
int board[15][15];
int Copy[15][15] = { 0, };
void make() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 2) Copy[i][j] = 0;
		}
	}
}
void back() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 2) Copy[i][j] = board[i][j];
		}
	}
}
int bfs(int x, int y) {
	queue<PP> q;
	q.push({ { x,y }, 0 });
	memset(Copy, 0, sizeof(Copy));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Copy[i][j] = board[i][j];
		}
	}
	bool visited[15][15] = { false, };
	for (int i = 0;i<15*15; i++) {
		queue<PP> temp;
		if (q.empty()) break;
		if (i % 3 == 2) make();
		else back();
		while (!q.empty()) {
			int x = q.front().first.first;
			int y = q.front().first.second;
			int ti = q.front().second;
			if (x == ex && y == ey) return ti;
			q.pop();
			visited[x][y] = true;
			for (int j = 0; j < 4; j++) {
				int nx = x + gox[j];
				int ny = y + goy[j];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny] || Copy[nx][ny] == 1 || Copy[nx][ny]==2) continue;
				else if (!visited[nx][ny]) {
					visited[nx][ny] = true;
					temp.push({ {nx,ny},ti+1});
				}
			}
			temp.push({ { x,y },ti + 1 });
		}
		q = temp;
	}
	return -1;
}
int main() {
	scanf("%d", &T);
	int Case = 1;
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf(" %d", &board[i][j]);
			}
		}
		scanf("%d%d", &sx, &sy);
		scanf("%d%d", &ex, &ey);
		if (sx == ex && sy == ey) printf("#%d %d\n", Case++, 0);
		else {
			int ans = bfs(sx, sy);
			printf("#%d %d\n", Case++, ans);
		}
	}
	return 0;
}