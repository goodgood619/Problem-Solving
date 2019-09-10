#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
char board[105][105];
int gox[8] = {0,1,-1,0,1,-1,1,-1};
int goy[8] = {1,0,0,-1,1,-1,-1,1};
int n, m,cnt;
bool visited[105][105];
//# 갯수
typedef pair<int, int> P;
queue <P> q;
void bfs(int x, int y) {
	q.push({ x,y });
	visited[x][y] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx<1 || nx>n || ny<1 || ny>m || visited[nx][ny] || board[nx][ny] == '.') continue;
			else if (!visited[nx][ny]) {
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
	cnt++;
}
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &board[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++){
			if (!visited[i][j] && board[i][j] == '#') {
				bfs(i, j);
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}