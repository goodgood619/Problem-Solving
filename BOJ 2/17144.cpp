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
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int board[51][51];
int n, m, t,sx=-1,sy=-1,ex,ey;
void check1(int sx,int sy) {
	deque<int> d;
	for (int j = sy + 1; j <= m; j++) {
		d.push_back(board[sx][j]);
		board[sx][j] = 0;
	}
	for (int i = sx-1; i >= 1; i--) {
		d.push_back(board[i][m]);
		board[i][m] = 0;
	}
	for (int j = m-1; j >= 1; j--) {
		d.push_back(board[1][j]);
		board[1][j] = 0;
	}
	for (int i = 2; i < sx; i++) {
		d.push_back(board[i][1]);
		board[i][1] = 0;
	}


	for (int j = sy + 2; j <= m; j++) {
		board[sx][j] = d.front();
		d.pop_front();
	}
	for (int i = sx-1; i >= 1; i--) {
		board[i][m] = d.front();
		d.pop_front();
	}
	for (int j = m-1; j >= 1; j--) {
		board[1][j] = d.front();
		d.pop_front();
	}
	for (int i = 2; i < sx; i++) {
		board[i][1] = d.front();
		d.pop_front();
	}

}
void check2(int ex,int ey) {
	deque<int> d;
	for (int j = ey + 1; j <= m; j++) {
		d.push_back(board[ex][j]);
		board[ex][j] = 0;
	}
	for (int i = ex+1; i<=n; i++) {
		d.push_back(board[i][m]);
		board[i][m] = 0;
	}
	for (int j = m-1; j >= 1; j--) {
		d.push_back(board[n][j]);
		board[n][j] = 0;
	}
	for (int i = n-1; i >ex; i--) {
		d.push_back(board[i][1]);
		board[i][1] = 0;
	}


	for (int j = ey + 2; j <= m; j++) {
		board[ex][j] = d.front();
		d.pop_front();
	}
	for (int i = ex+1; i<=n; i++) {
		board[i][m] = d.front();
		d.pop_front();
	}
	for (int j = m - 1; j >= 1; j--) {
		board[n][j] = d.front();
		d.pop_front();
	}
	for (int i = n-1; i > ex; i--) {
		board[i][1] = d.front();
		d.pop_front();
	}

}
void bfs() {
	int cnt = 0;
	for (int i = 1; i <= t; i++) {
		queue<P> q;
		int temp = 0;
		int Copy[51][51] = { 0, };
		map<P, int> mm;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (board[i][j] > 0) {
					q.push({ i,j });
				}
			}
		}

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + gox[i];
				int ny = y + goy[i];
				if (nx<1 || nx>n || ny<1 || ny>m || board[nx][ny] == -1) continue;
				else {
					Copy[nx][ny]+= board[x][y] / 5;
					mm[{x, y}]++;
				}
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				board[i][j] = board[i][j] - board[i][j] / 5 * mm[{i, j}];
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				board[i][j]=Copy[i][j] + board[i][j];
			}
		}

		check1(sx, sy);
		check2(ex, ey);

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (board[i][j] == -1) continue;
				temp += board[i][j];
			}
		}
		cnt = temp;
	}
	printf("%d\n", cnt);
}
int main() {
	scanf("%d%d%d", &n, &m, &t);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %d", &board[i][j]);
			if (board[i][j] == -1) {
				if (sx == -1 && sy == -1) {
					sx = i, sy = j;
				}
				else {
					ex = i, ey = j;
				}
			}
		}
	}

	bfs();
	return 0;
}