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
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, Case = 1,sx,sy,ex,ey;
char board[11][11];
int bfs(int x,int y) {
	queue<PPP> q;
	q.push({ 0,{x,y} });
	bool visited[11][11] = { false, };
	visited[x][y] = true;
	while (!q.empty()) {
		int cnt = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();
		if (x == ex && y == ey) return cnt - 1;
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx < 1 || nx>10 || ny < 1 || ny>10 || visited[nx][ny] || board[nx][ny] == 'R') continue;
			else {
				visited[nx][ny] = true;
				q.push({ cnt + 1,{nx,ny} });
			}
		}
	}
}
int main() {
	setbuf(stdout, NULL);
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			scanf(" %c", &board[i][j]);
			if (board[i][j] == 'L') sx = i, sy = j;
			if (board[i][j] == 'B') ex = i, ey = j;
		}
	}
	printf("%d\n",bfs(sx, sy));
	return 0;
}