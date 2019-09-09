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
char board[25][25];
bool check[26];
bool visited[25][25];
int n, m;
int dfs(int x, int y,int cnt) {
	visited[x][y] = true;
	check[board[x][y] - 'A'] = true;
	int ret = cnt;
	for (int i = 0; i < 4; i++) {
		int nx = x + gox[i];
		int ny = y + goy[i];
		if (nx<1 || nx>n || ny<1 || ny>m || visited[nx][ny] || check[board[nx][ny] - 'A']) continue;
		ret = max(ret, dfs(nx, ny, cnt + 1));
	}
	visited[x][y] = false;
	check[board[x][y] - 'A'] = false;
	return ret;
}
int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &board[i][j]);
		}
	}
	printf("%d\n", dfs(1, 1,1));
	return 0;
}