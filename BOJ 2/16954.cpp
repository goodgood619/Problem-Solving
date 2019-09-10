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
typedef pair <int, int > P;
typedef pair<pair<int, int>, int> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[8] = { 0,1,-1,0,1,1,-1,-1 };
int goy[8] = { 1,0,0,-1,-1,1,1,-1 };
char board[9][9];
int sx = 8, sy = 1, ex = 1, ey = 8;
void move() {
	for (int i = 7; i >= 1; i--) {
		for (int j = 1; j <= 8; j++) {
			board[i + 1][j] = board[i][j];
		}
	}
	for (int i = 1; i <= 8; i++) {
		board[1][i] = '.';
	}
}
int bfs() {
	queue<P> q;
	q.push({ sx,sy });
	while (1) {
		queue<P> temp;
		bool visited[9][9] = { false, };
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			temp.push({ x,y });//본인위치도 넣어주고
			visited[x][y] = true;
			q.pop();
			if (x == ex && y == ey) return 1;
			for (int i = 0; i < 8; i++) {
				int nx = x + gox[i];
				int ny = y + goy[i];
				if (nx < 1 || nx>8 || ny < 1 || ny>8 || board[nx][ny] == '#' || visited[nx][ny]) continue;
				else if (board[nx][ny] == '.') {
					visited[nx][ny] = true;
					temp.push({ nx,ny }); // 8방향넣어주고
				}
			}
		}
		move();
		while (!temp.empty()) {
			int x = temp.front().first;
			int y = temp.front().second;
			temp.pop();
			if (board[x][y] == '#') continue;
			q.push({ x,y });
		}
		if (q.empty()) break;
	}
	return 0;
}
int main(void) {
	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			scanf(" %c", &board[i][j]);
		}
	}
	printf("%d\n", bfs());
	return 0;
}