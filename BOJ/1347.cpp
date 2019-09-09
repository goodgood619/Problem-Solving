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
using namespace std;
typedef long long ll;
#define INF 1000000000
typedef pair<int,int> P;
typedef pair<pair<int, int>,int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,0,-1 };
int goy[4] = { 1,0,-1,0 };
char board[105][105];
int n;
int main() {
	scanf("%d", &n);
	int sx = 52;
	int sy = 52;
	board[sx][sy] = '.';
	int dir = 1; // 초기방향 남쪽
	for (int i = 1; i <= n; i++) {
		char c;
		scanf(" %c", &c);
		if (c == 'L') {
			dir -= 1;
			if (dir<0) dir = 3;
		}
		else if (c == 'R') {
			dir += 1;
			if (dir == 4) dir = 0;
		}
		else {
			int nx = sx + gox[dir];
			int ny = sy + goy[dir];
			board[nx][ny] = '.';
			sx = nx;
			sy = ny;
		}
	}
	int mx = 0;
	int my = 0;
	int Minx = 1e9;
	int Miny = 1e9;
	for (int i = 1; i <= 104; i++) {
		for (int j = 1; j <= 104; j++) {
			if (board[i][j] == '.') {
				mx = max(mx, i);
				my = max(my, j);
				Minx = min(Minx, i);
				Miny = min(Miny, j);
			}
		}
	}
	for (int i = Minx; i <= mx; i++) {
		for (int j = Miny; j <= my; j++) {
			if (board[i][j] != '.') {
				board[i][j] = '#';
			}
		}
	}
	for (int i = Minx; i <= mx; i++) {
		for (int j = Miny; j <= my; j++) {
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
	return 0;
}