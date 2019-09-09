#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
char board[50][50];
bool visited[50][50];
int gox[4] = {0,-1,0,1};
int goy[4] = {1,0,-1,0};
int t, n, m,k,cnt;
typedef pair <int, int> P;
queue <P> q;
void bfs(int x, int y){
	visited[x][y] = true;
	q.push({ x,y });
	while (!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx < 0 || nx>n - 1 || ny < 0 || ny>m - 1 || visited[nx][ny] || board[nx][ny] == '\0') continue;
			if (!visited[nx][ny] && board[nx][ny] == '1') {
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
	cnt++;
}
int main() {
	scanf("%d", &t);
	while (t--){
		cnt = 0;
		scanf("%d%d%d", &m, &n, &k);
		for (int i = 1; i <= k; i++) {
			int s, t;
			scanf("%d%d", &s, &t);
			board[t][s] = '1';
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == '1' && !visited[i][j])
					bfs(i, j);
			}
		}
		printf("%d\n", cnt);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == '1') board[i][j] = '\0';
				if (visited[i][j]) visited[i][j] = false;
			}
		}

	}
	return 0;
}
