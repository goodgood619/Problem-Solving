#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;
char b, board[1005][1005];
int n, m, check[1005][1005], ans, cycle=1, buffer;
void bfs(int i, int j) {
	queue<pair<int, int>> q;
	q.push({ i,j });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (!check[x][y]) {
			check[x][y] = cycle;
			if (board[x][y] == 'S') q.push({ x + 1,y });
			else if (board[x][y] == 'N') q.push({ x - 1,y });
			else if (board[x][y] == 'E') q.push({ x ,y + 1 });
			else if (board[x][y] == 'W') q.push({ x ,y - 1 });
		}
		else {
			if (check[x][y] == cycle) {
				ans++;
				return;
			}
		}

	}
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %1c", &board[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!check[i][j]) {
				bfs(i, j);
				cycle++;
			}
		}
	}
	printf("%d", ans);
}