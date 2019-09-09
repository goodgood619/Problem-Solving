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
int gox[4] = { 0, -1,0,1 };
int goy[4] = { 1, 0,-1,0 };
char board[11][11];
int n, m, rx, ry, bx, by, ex, ey;
int make(int x, int y, int dir) { //우선 길이를 계산함, 빨강색이 파랑색을 만나거나, 파랑색이 빨강색을 만나도 우선은 무시함
	for (int i = 1;; i++) {
		int nx = x + i * gox[dir];
		int ny = y + i * goy[dir];
		if (nx<1 || nx>n || ny<1 || ny>m || board[nx][ny] == '#') return i - 1;
		if (board[nx][ny] == 'O') return i;
	}
}
int dfs(int rx, int ry, int bx, int by, int cnt) {
	if (cnt >= 11) return 1e9;
	int ret = 1e9;
	if (ex == rx && ey == ry) {
		if (bx != ex || by != ey) return cnt; //빨강색만 들어감
		if (bx == ex && by == ey) return 1e9;// 파랑색도 같이 들어감
	}
	if (bx == ex && by == ey) return 1e9;
	for (int i = 0; i < 4; i++) {
		if (i == 0) { //동
			int length1 = make(rx, ry, i), length2 = make(bx, by, i);
			int nrx = rx, nry = ry + length1, nbx = bx, nby = by + length2;
			if (nrx == nbx && nry == nby && board[nrx][nry] != 'O') { //일치한다면, 빨강색이 더 서쪽에 있거나, 파란색이 더 서쪽에 있을것이다.
				if (ry < by) nry--;
				else nby--;
			}
			ret = min(ret, dfs(nrx, nry, nbx, nby, cnt + 1));
		}
		else if (i == 1) { //북
			int length1 = make(rx, ry, i), length2 = make(bx, by, i);
			int nrx = rx - length1, nry = ry, nbx = bx - length2, nby = by;
			if (nrx == nbx && nry == nby && board[nrx][nry] != 'O') { //일치한다면, 빨강색이 더 서쪽에 있거나, 파란색이 더 서쪽에 있을것이다.
				if (rx < bx) nbx++;
				else nrx++;
			}
			ret = min(ret, dfs(nrx, nry, nbx, nby, cnt + 1));
		}
		else if (i == 2) { //서
			int length1 = make(rx, ry, i), length2 = make(bx, by, i);
			int nrx = rx, nry = ry - length1, nbx = bx, nby = by - length2;
			if (nrx == nbx && nry == nby && board[nrx][nry] != 'O') { //일치한다면, 빨강색이 더 서쪽에 있거나, 파란색이 더 서쪽에 있을것이다.
				if (ry > by) nry++;
				else nby++;
			}
			ret = min(ret, dfs(nrx, nry, nbx, nby, cnt + 1));
		}
		else {//남
			int length1 = make(rx, ry, i), length2 = make(bx, by, i);
			int nrx = rx + length1, nry = ry, nbx = bx + length2, nby = by;
			if (nrx == nbx && nry == nby && board[nrx][nry] != 'O') { //일치한다면, 빨강색이 더 서쪽에 있거나, 파란색이 더 서쪽에 있을것이다.
				if (rx < bx) nrx--;
				else nbx--;
			}
			ret = min(ret, dfs(nrx, nry, nbx, nby, cnt + 1));
		}
	}
	return ret;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &board[i][j]);
			if (board[i][j] == 'R') { rx = i, ry = j; }
			if (board[i][j] == 'B') { bx = i, by = j; }
			if (board[i][j] == 'O') { ex = i, ey = j; }
		}
	}

	int ans = dfs(rx, ry, bx, by, 0);
	ans == 1e9 ? printf("-1\n") : printf("%d\n", ans);
	return 0;
}