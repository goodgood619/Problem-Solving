#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n,k;
int board[30][30];
bool visited[30][30];
int ans[900];
int gox[4] = {0,0,1,-1};
int goy[4] = {1,-1,0,0};
queue <pair<int, int>> q;
int bfs(int x, int y) {
	int cnt = 1;
	visited[x][y] = true;
	q.push({ x,y });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx<1 || nx>n || ny<1 || ny>n || visited[nx][ny] || board[nx][ny] == 0) continue;
			if (!visited[nx][ny] && board[nx][ny] == 1) {
				visited[nx][ny] = true;
				q.push({ nx,ny });
				cnt++;
			}
		}
	}
	return cnt;
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%1d", &board[i][j]);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!visited[i][j] && board[i][j] == 1) {
				ans[k++]=bfs(i, j);
			}
		}
	}
	printf("%d\n", k);
	sort(ans, ans + k);
	for (int i = 0; i < k; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}