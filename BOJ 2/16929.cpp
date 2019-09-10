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
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n, m;
bool visited[55][55];
int num[55][55];
char board[55][55];
void dfs(int x, int y, int k) {
	visited[x][y] = true;
	num[x][y] = k;
	bool check = false;
	for (int i = 0; i < 4; i++) {
		int nx = x + gox[i];
		int ny = y + goy[i];
		if (nx<1 || nx>n || ny<1 || ny>m || visited[nx][ny] || board[x][y] != board[nx][ny]) continue;
		if (!visited[nx][ny]) {
			check = true;
			dfs(nx, ny, k + 1);
		}
	}
	if (k < 4) return;
	if (k >= 4) {
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx<1 || nx>n || ny<1 || ny>m || board[x][y] != board[nx][ny]) continue;
			if (board[x][y] == board[nx][ny] && num[nx][ny]==1) {
				printf("Yes\n");
				exit(0);
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &board[i][j]);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			memset(visited, false, sizeof(visited));
			memset(num, 0, sizeof(visited));
			dfs(i, j, 1);
		}
	}
	printf("No\n");
	return 0;
}