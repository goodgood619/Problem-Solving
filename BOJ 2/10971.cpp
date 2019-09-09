#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int n;
int board[15][15];
bool visited[15];
#define INF 1e8
int go(int x, int sum, int city, int start) {
	if (city == n) {
		return min((int)INF, sum + board[x][start]);
	}
	int ret = INF;
	for (int i = 1; i <= n; i++) {
		if (i == x) continue;
		if (!visited[i]) {
			visited[i] = true;
			ret = min(ret, go(i, sum + board[x][i], city + 1, start));
			visited[i] = false;
		}
	}
	return ret;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %d", &board[i][j]);
			if (board[i][j] == 0) board[i][j] = INF;
		}
	}
	int ans = INF;
	for (int i = 1; i <= n; i++) {
		visited[i] = true;
		ans = min(ans, go(i, 0, 1, i));
		visited[i] = false;
	}
	printf("%d\n", ans);
	return 0;
}