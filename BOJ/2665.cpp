#include <cstdio>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>
#include <cstring>
using namespace std;
int n;
int board[55][55];
bool visited[55][55];
int gox[4] = {0,1,-1,0};
int goy[4] = {1,0,0,-1};
void dfs(int x, int y) {
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + gox[i];
		int ny = y + goy[i];
		if (nx<1 || nx>n || ny<1 || ny>n || visited[nx][ny] || board[x][y]==0) continue;
		else if (!visited[nx][ny]){
			dfs(nx, ny);
			board[nx][ny] = 1;
		}
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%1d", &board[i][j]);
		}
	}
	int cnt = 0;
	while (1) {
			dfs(1, 1);
			if (visited[n][n]) break;
			memset(visited, false, sizeof(visited));
			cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}