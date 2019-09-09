#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
char board1[101][101];
char board2[101][101];
bool visited[101][101];
int n,cnt1,cnt2;
int gox[4] = {0,-1,0,1};
int goy[4] = {1,0,-1,0};
typedef pair <int, int> P;
queue <P> q;
void bfs(int x, int y) {
	visited[x][y] = true;
	q.push({ x,y });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx < 1 || nx>n || ny<1 || ny>n || board1[x][y] != board1[nx][ny] || visited[nx][ny]) continue;
			if (!visited[nx][ny]) {
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
	cnt1++;
}
void bfs2(int x, int y) {
	visited[x][y] = true;
	q.push({ x,y });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx < 1 || nx>n || ny<1 || ny>n || board2[x][y] != board2[nx][ny] || visited[nx][ny]) continue;
			if (!visited[nx][ny]) {
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
	cnt2++;
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %c", &board1[i][j]);
			if (board1[i][j] == 'G') board2[i][j] = 'R';
			else board2[i][j] = board1[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!visited[i][j]) {
				bfs(i, j);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (visited[i][j]) visited[i][j] = false;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!visited[i][j]) {
				bfs2(i, j);
			}
		}
	}
	printf("%d %d\n", cnt1, cnt2);
	return 0;
}