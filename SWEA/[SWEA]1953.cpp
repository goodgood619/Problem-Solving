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
typedef pair<int, int> P;
typedef pair<pair<int, int>, pair<int, int>> PPP;
using namespace std;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int board[52][52];
int dp[52][52];
bool visited[52][52];
int n, m, sx, sy, ti, Case = 1;
// 0: 동,1:남,2:북,3:서
int go(int px, int py, int x, int y, int cnt) {
	if (cnt > ti) return 0;
	int ret = 1;
	visited[x][y] = true;
	dp[x][y] = 1;
	bool first = false;
	for (int i = 0; i < 4; i++) {
		int nx = x + gox[i];
		int ny = y + goy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] == 0 || visited[nx][ny]) continue;
		else if (!visited[nx][ny]) {
			if (board[x][y] == 1) {
				if (i == 0) {
					if (board[nx][ny] == 2 || board[nx][ny] == 4 || board[nx][ny] == 5) continue;
					ret += go(x, y, nx, ny, cnt + 1);
				}
				else if (i == 1) {
					if (board[nx][ny] == 3 || board[nx][ny] == 5 || board[nx][ny] == 6) continue;
					ret += go(x, y, nx, ny, cnt + 1);
				}
				else if (i == 2) {
					if (board[nx][ny] == 3 || board[nx][ny] == 4 || board[nx][ny] == 7) continue;
					ret += go(x, y, nx, ny, cnt + 1);
				}
				else {
					if (board[nx][ny] == 2 || board[nx][ny] == 6 || board[nx][ny] == 7) continue;
					ret += go(x, y, nx, ny, cnt + 1);
				}
			}
			else if (board[x][y] == 2) {
				if (i == 1) {
					if (board[nx][ny] == 3 || board[nx][ny] == 5 || board[nx][ny] == 6) continue;
					ret += go(x, y, nx, ny, cnt + 1);
				}
				else if (i == 2) {
					if (board[nx][ny] == 3 || board[nx][ny] == 4 || board[nx][ny] == 7) continue;
					ret += go(x, y, nx, ny, cnt + 1);
				}
			}
			else if (board[x][y] == 3) {
				if (i == 0) {
					if (board[nx][ny] == 2 || board[nx][ny] == 4 || board[nx][ny] == 5) continue;
					ret += go(x, y, nx, ny, cnt + 1);
				}
				else if (i == 3) {
					if (board[nx][ny] == 2 || board[nx][ny] == 6 || board[nx][ny] == 7) continue;
					ret += go(x, y, nx, ny, cnt + 1);
				}
			}
			else if (board[x][y] == 4) {
				if (i == 0) {
					if (board[nx][ny] == 2 || board[nx][ny] == 5 || board[nx][ny]==4) continue;
					ret += go(x, y, nx, ny, cnt + 1);
				}
				else if (i == 2) {
					if (board[nx][ny] == 3 || board[nx][ny] == 7 || board[nx][ny]==4) continue;
					ret += go(x, y, nx, ny, cnt + 1);
				}
			}
			else if (board[x][y] == 5) {
				if (i == 0) {
					if (board[nx][ny] == 2 || board[nx][ny] == 4 || board[nx][ny]==5) continue;
					ret += go(x, y, nx, ny, cnt + 1);
				}
				else if (i == 1) {
					if (board[nx][ny] == 3 || board[nx][ny] == 6 || board[nx][ny]==5) continue;
					ret += go(x, y, nx, ny, cnt + 1);
				}
			}
			else if (board[x][y] == 6) {
				if (i == 1) {
					if (board[nx][ny] == 5 || board[nx][ny] == 3 || board[nx][ny]==6) continue;
					ret += go(x, y, nx, ny, cnt + 1);
				}
				else if (i == 3) {
					if (board[nx][ny] == 2 || board[nx][ny] == 7 || board[nx][ny]==6) continue;
					ret += go(x, y, nx, ny, cnt + 1);
				}
			}
			else if (board[x][y] == 7) {
				if (i == 2) {
					if (board[nx][ny] == 3 || board[nx][ny] == 4 || board[nx][ny]==7) continue;
					ret += go(x, y, nx, ny, cnt + 1);
				}
				else if (i == 3) {
					if (board[nx][ny] == 2 || board[nx][ny] == 6 || board[nx][ny]==7) continue;
					ret += go(x, y, nx, ny, cnt + 1);
				}
			}
		}
	}
	visited[x][y] = false;
	return ret;
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(visited, false, sizeof(visited));
		memset(board, 0, sizeof(board));
		memset(dp, 0, sizeof(dp));
		scanf(" %d %d %d %d %d", &n, &m, &sx, &sy, &ti);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf(" %d", &board[i][j]);
			}
		}
		go(sx, sy, sx, sy, 1);
		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (dp[i][j] == 0) continue;
				ans += (dp[i][j] == 1);
			}
		}
		printf("#%d %d\n", Case++, ans);
	}
	return 0;
}
