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
int t, Case = 1,n,k;
int board[9][9];
bool visited[9][9];
int dfs(int x, int y, int cnt, int flag) {
	int ret = cnt;
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + gox[i];
		int ny = y + goy[i];
		if (nx<1 || nx>n || ny<1 || ny>n || visited[nx][ny]) continue;
		if (board[x][y] > board[nx][ny]) ret = max(ret, dfs(nx, ny, cnt + 1, flag));
		else if (flag == 0) {
			for (int j = 1; j <= k; j++) {
				board[nx][ny] -= j;
				if (board[x][y] > board[nx][ny]) ret = max(ret, dfs(nx, ny, cnt + 1, 1));
				board[nx][ny] += j;
			}
		}
	}
	visited[x][y] = false;
	return ret;
}
int main(void) {
	scanf("%d", &t);
	while (t--) {	
		scanf("%d%d", &n, &k);
		memset(board, 0, sizeof(board));
		memset(visited, false, sizeof(visited));
		int Max = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				scanf(" %d", &board[i][j]);
				Max = max(Max, board[i][j]);
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (board[i][j] == Max) {
					ans = max(ans, dfs(i, j, 1, 0));
				}
			}
		}
		printf("#%d %d\n",Case++,ans);
	}
	return 0;
}