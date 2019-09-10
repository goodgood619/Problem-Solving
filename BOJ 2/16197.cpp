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
typedef pair<int, ll> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0};
int goy[4] = { 1,0,0,-1};
int n, m,sx,sy,ex,ey;
char board[25][25];
bool check(int sx, int sy, int ex, int ey) {
	if (sx == 0 && ex == 0) return true;
	if (sy == 0 && ey == 0) return true;
	if (sx == n + 1 && ex == n + 1) return true;
	if (sy == m + 1 && ey == m + 1) return true;
	return false;
}
int go(int sx, int sy, int ex, int ey, int cnt) {
	if (cnt >= 11) return 1e9;
	if (sx <= 0 || sx > n || ex <= 0 || ex > n || sy <= 0 || sy > m || ey <= 0 || ey > m) {
		if (check(sx, sy, ex, ey)) return 1e9;
		else return 0;
	}
	int ret = 1e9;
	for (int i = 0; i < 4; i++) {
		int nx1 = sx + gox[i];
		int ny1 = sy + goy[i];
		int nx2 = ex + gox[i];
		int ny2 = ey + goy[i];
		if (board[nx1][ny1] == '#' && board[nx2][ny2] == '#') continue;
		else if (board[nx1][ny1] != '#' && board[nx2][ny2] == '#') ret = min(ret, go(nx1, ny1, ex, ey, cnt + 1) + 1);
		else if (board[nx1][ny1] == '#' && board[nx2][ny2] != '#') ret = min(ret, go(sx, sy, nx2, ny2, cnt + 1) + 1);
		else ret = min(ret, go(nx1, ny1, nx2, ny2, cnt + 1) + 1);
	}
	return ret;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &board[i][j]);
			if (board[i][j] == 'o') {
				if (sx == 0) {
					sx = i,sy=j;
				}
				else ex = i, ey = j;
			}
		}
	}
	int ans=go(sx, sy, ex, ey, 0);
	ans == 1e9 ? printf("-1\n") : printf("%d\n", ans);
	return 0;
}