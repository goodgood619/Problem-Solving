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
int gox[4] = { 1,1,-1,-1 };
int goy[4] = { 1,-1,-1,1 };
int t, Case = 1,n,k,ans;
int board[25][25];
bool visited[25][25];
int eat[105];
void dfs(int sx,int sy,int x, int y, int cnt, int dir) {
	if (visited[sx][sy] && cnt >= 4 && x==sx && y==sy) {
		ans = max(ans, cnt);
		return;
	}
	if (eat[board[x][y]] != 0 || visited[x][y]) return;
	int ret = cnt;
	visited[x][y] = true;
	eat[board[x][y]] = 1;
	for (int i = dir; i < 4; i++) {
		int nx = x + gox[i];
		int ny = y + goy[i];
		if (nx<1 || nx>n || ny<1 || ny>n) continue;
		dfs(sx, sy, nx, ny, cnt + 1, i);
	}
	visited[x][y] = false;
	eat[board[x][y]] = 0;
	return;
}
int main(void) {
	scanf("%d", &t);
	while (t--) {	
		scanf("%d", &n);
		memset(board, 0, sizeof(board));
		memset(visited, false, sizeof(visited));
		ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				scanf(" %d", &board[i][j]);
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
					dfs(i,j,i, j, 0,0);
			}
		}
		if (ans == 0) ans = -1;
		printf("#%d %d\n",Case++,ans);
	}
	return 0;
}