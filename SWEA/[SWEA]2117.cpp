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
typedef pair < int,int > P;
typedef pair<int,pair<int, int>> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, Case = 1, n, m;
int board[25][25];
int bfs(int x, int y) {
	int cnt = 0;
	if (board[x][y] == 1) cnt = 1;
	queue<P> q;
	bool visited[25][25] = { false, };
	q.push({ x,y });
	visited[x][y] = true;
	int ans = 0;
	ans = max(ans, cnt);
	for (int i = 1; i <= 2 * n; i++) {
		queue<P> temp;
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + gox[i];
				int ny = y + goy[i];
				if (nx<1 || nx>n || ny<1 || ny>n || visited[nx][ny]) continue;
				else if (!visited[nx][ny]) {
					temp.push({ nx,ny });
					visited[nx][ny] = true;
					if (board[nx][ny] == 1) cnt++;
				}
			}
		}
		q = temp;
		if (cnt*m >= (i+1) * (i+1) + i*i) {
			ans = max(ans, cnt);
		}
	}
	return ans;
}
int main(void) {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		memset(board, 0, sizeof(board));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				scanf(" %d", &board[i][j]);
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				ans = max(ans, bfs(i, j));
			}
		}
		printf("#%d %d\n", Case++, ans);
	}
	return 0;
}