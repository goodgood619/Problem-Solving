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
#define mod 1000000009
#define lim 1000000000
typedef pair < ll, ll > P;
typedef pair<pair<int, int>, int> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int board[2001][2001];
int n, m, r, c, sx, sy, ex, ey;
bool check(int x,int y,int dir) {
	if (dir == 0) { // 동쪽
		int nx = x + r*gox[dir];
		int ny = y + c*goy[dir];
		for (int i = 0; i < r; i++) {
			if (board[nx][ny] == 1 || nx<1 || nx>n || ny<1 || ny>m) return true;
			nx++;
		}
	}
	else if (dir == 1) { // 남쪽
		int nx = x + r*gox[dir];
		int ny = y + c*goy[dir];
		for (int i = 0; i < c; i++) {
			if (board[nx][ny] == 1 || nx<1 || nx>n || ny<1 || ny>m) return true;
			ny++;
		}
	}
	else if (dir == 2) { // 북쪽
		int nx = x + gox[dir];
		int ny = y + goy[dir];
		for (int i = 0; i <c; i++) {
			if (board[nx][ny] == 1 || nx<1 || nx>n || ny<1 || ny>m) return true;
			ny++;
		}
	}
	else { // 서쪽
		int nx = x + gox[dir];
		int ny = y + goy[dir];
		for (int i = 0; i < r; i++) {
			if (board[nx][ny] == 1 || nx<1 || nx>n || ny<1 || ny>m) return true;
			nx++;
		}
	}
	return false;
}
int bfs(int x, int y) {
	queue<PP> q;
	q.push({{ x,y }, 0});
	bool visited[1005][1005] = { false, };
	visited[x][y] = true;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		if (x == ex && y == ey) return cnt;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx<1 || nx>n || ny<1 || ny>m || visited[nx][ny] || board[nx][ny]==1) continue;
			if (check(x, y, i)) continue;
			if (!visited[nx][ny]) {
				visited[nx][ny] = true;
				q.push({{ nx,ny }, cnt + 1});
			}
		}
	}
	return -1;
}
int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %d", &board[i][j]);
		}
	}

	scanf("%d%d%d%d%d%d", &r, &c, &sx, &sy, &ex, &ey);
	printf("%d\n", bfs(sx, sy));
	return 0;
}