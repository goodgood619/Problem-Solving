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
int m, n;
int board[1002][1002];
bool visited[1002][1002];
int bfs() {
	queue<PP> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (board[i][j] == 1) {
				q.push({ { i,j }, 0 });
				visited[i][j] = true;
			}
		}
	}
	int Max = 0;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		Max = max(Max, cnt);
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx<1 || nx>n || ny<1 || ny>m || visited[nx][ny] || board[nx][ny] == -1 || board[nx][ny]==1) continue;
			else if (!visited[nx][ny] && board[nx][ny]==0) {
				visited[nx][ny] = true;
				q.push({ {nx,ny }, cnt + 1 });
				board[nx][ny] = 1;
			}
		}
	}
	return Max;
}
int main(void) {
	scanf("%d%d", &m, &n);
	int zero = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %d", &board[i][j]);
			zero += (board[i][j] == 0);
		}
	}
	if (zero == 0) { //애초에 다익음
		printf("0\n");
		return 0;
	}
	int ans=bfs();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (board[i][j] == 0) {
				printf("-1\n");
				return 0;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}