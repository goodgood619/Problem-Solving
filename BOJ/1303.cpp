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
typedef pair<int, int> P;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = {0,1,-1,0};
int goy[4] = {1,0,0,-1};
int n, m,white,blue;
char board[101][101];
bool visited[101][101];
int go(int x, int y) {
	int ret = 1;
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + gox[i];
		int ny = y + goy[i];
		if (nx<1 || nx>n || ny<1 || ny>m || board[x][y] != board[nx][ny] || visited[nx][ny]) continue;
		ret += go(nx, ny);
	}
	return ret;
}
int main(void) {
	scanf("%d%d", &n, &m);
	swap(n, m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &board[i][j]);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!visited[i][j] && board[i][j] == 'W') {
				int temp = go(i, j);
				white += temp * temp;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!visited[i][j] && board[i][j] == 'B') {
				int temp = go(i, j);
				blue += temp * temp;
			}
		}
	}
	printf("%d %d\n", white, blue);
	return 0;
}