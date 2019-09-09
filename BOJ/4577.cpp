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
typedef pair<double, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<double, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, Case = 1,n,m,sx,sy,cnt;
char board[16][16];
string s;
pair<int,int> go2(int x,int y,int dir) {
	int nx = x + gox[dir], ny = y + goy[dir];
	if (nx<1 || nx>n || ny<1 || ny>m || board[nx][ny] == '#') return {x,y};
	if (board[nx][ny] == '.' || board[nx][ny] == '+') {
		board[x][y] == 'W' ? board[x][y] = '+' : board[x][y] = '.';
		board[nx][ny] == '+' ? board[nx][ny] = 'W' : board[nx][ny] = 'w';
		x = nx, y = ny;
	}
	else {
		int nnx = nx + gox[dir], nny = ny + goy[dir];
		if (nnx<1 || nnx>n || nny<1 || nny>m) return {x,y};
		if (board[nx][ny] == 'b' && board[nnx][nny] == '.') {
			board[nnx][nny] = 'b';
			board[nx][ny] = 'w';
			board[x][y] == 'W' ? board[x][y] = '+' : board[x][y] = '.';
			x = nx, y = ny;
		}
		else if (board[nx][ny] == 'b' && board[nnx][nny] == '+') {
			board[nnx][nny] = 'B';
			board[nx][ny] = 'w';
			board[x][y] == 'W' ? board[x][y] = '+' : board[x][y] = '.';
			x = nx, y = ny;
		}
		else if (board[nx][ny] == 'B' && board[nnx][nny] == '.') {
			board[nnx][nny] = 'b';
			board[nx][ny] = 'W';
			board[x][y] == 'W' ? board[x][y] = '+' : board[x][y] = '.';
			x = nx, y = ny;
		}
		else if (board[nx][ny] == 'B' && board[nnx][nny] == '+') {
			board[nnx][nny] = 'B';
			board[nx][ny] = 'W';
			board[x][y] == 'W' ? board[x][y] = '+' : board[x][y] = '.';
			x = nx, y = ny;
		}
	}
	return { x,y };
}
void go(int sx,int sy) {
	int x = sx, y = sy;
	for (int i = 0; i < s.size(); i++) {
		char c = s[i];
		if (c == 'R') {
			pair<int,int> a = go2(x, y, 0);
			x = a.first, y = a.second;
		}
		else if (c == 'D') {
			pair<int, int> a = go2(x, y,1);
			x = a.first, y = a.second;
		}
		else if (c == 'U') {
			pair<int, int> a = go2(x, y,2);
			x = a.first, y = a.second;
		}
		else {
			pair<int, int> a = go2(x, y,3);
			x = a.first, y = a.second;
		}
		int cnt2 = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (board[i][j] == 'B') cnt2++;
			}
		}
		if (cnt == cnt2) {
			printf("Game %d: complete\n", Case++);
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					printf("%c", board[i][j]);
				}
				printf("\n");
			}
			return;
		}
	}
	printf("Game %d: incomplete\n", Case++);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
}
int main() {
	setbuf(stdout, NULL);
	while (true) {
		scanf("%d%d", &n, &m);
		sx = -1, sy = -1,cnt=0;
		s.clear();
		if (n == 0 && m == 0) break;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				scanf(" %c", &board[i][j]);
				if (board[i][j] == 'w' || board[i][j] == 'W') {
					sx = i, sy = j;
					if (board[i][j] == 'W') cnt++;
				}
				if (board[i][j] == '+' || board[i][j]=='B') cnt++;
			}
		}
		cin >> s;
		go(sx, sy);
	}
	return 0;
}