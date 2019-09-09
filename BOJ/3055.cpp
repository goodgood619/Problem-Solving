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
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
char board[52][52];
int n, m,sx,sy,ex,ey;
int bfs(int sx, int sy, int ex, int ey) {
	queue<P> water;
	queue<PP> mouse;
	bool watervisit[52][52] = { false, };
	bool mousevisit[52][52] = { false, };
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (board[i][j] == '*') {
				water.push({ i,j });
				watervisit[i][j] = true;
			}
		}
	}
	mouse.push({ {sx,sy }, 0 });
	mousevisit[sx][sy] = true;
	while (1) {
		queue<P> tempwater;
		queue<PP> tempmouse;
		//물부터 퍼뜨린다. 그다음에 고슴도치가 갈수있는지를 판단한다
		while (!water.empty()) {
			int x = water.front().first;
			int y = water.front().second;
			water.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + gox[i];
				int ny = y + goy[i];
				if (nx<1 || nx>n || ny<1 || ny>m || watervisit[nx][ny] || board[nx][ny]=='D' || board[nx][ny]=='X') continue;
				else if (!watervisit[nx][ny]) {
					watervisit[nx][ny] = true;
					tempwater.push({ nx,ny });
					board[nx][ny] = '*';
				}
			}
		}
		if (mouse.empty()) break;
		while (!mouse.empty()) {
			int x = mouse.front().first.first;
			int y = mouse.front().first.second;
			int cnt = mouse.front().second;
			mouse.pop();
			if (x == ex && y == ey) return cnt;
			for (int i = 0; i < 4; i++) {
				int nx = x + gox[i];
				int ny = y + goy[i];
				if (nx<1 || nx>n || ny<1 || ny>m || mousevisit[nx][ny] || board[nx][ny] == '*' || watervisit[nx][ny] || board[nx][ny]=='X') continue;
				else if (!mousevisit[nx][ny]) {
					mousevisit[nx][ny] = true;
					tempmouse.push({ {nx,ny }, cnt + 1 });
				}
			}
		}
		mouse = tempmouse;
		water = tempwater;
	}


	return -1;
}
int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &board[i][j]);
			if (board[i][j] == 'S') sx = i, sy = j;
			if (board[i][j] == 'D') ex = i, ey = j;
		}
	}
	int ans = bfs(sx, sy, ex, ey);
	ans == -1 ? printf("KAKTUS\n") : printf("%d\n", ans);
	return 0;
}