#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
// v:늑대 k:양
char board[255][255];
bool visited[255][255];
int n, m,v,k,totalv,totalk;
int gox[4] = {0,1,-1,0};
int goy[4] = {1,0,0,-1};
typedef pair<int, int> P;
void bfs(int x, int y) {
	queue<P> q;
	q.push({ x,y });
	visited[x][y] = true;
	int tempv = 0;
	int tempk = 0;
	if (board[x][y] == 'k') tempk++;
	else if (board[x][y] == 'v') tempv++;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx<1 || nx>n || ny<1 || ny>m || visited[nx][ny] || board[nx][ny] == '#') continue;
			else if (!visited[nx][ny]) {
				visited[nx][ny] = true;
				if (board[nx][ny] == 'v') tempv++;
				else if (board[nx][ny] == 'k') tempk++;
				q.push({ nx,ny });
			}
		}
	}
	if (tempk > tempv) {
		totalv -= tempv;
	}
	else totalk -= tempk;
	return;
}
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &board[i][j]);
			if (board[i][j] == 'v') totalv++;
			else if (board[i][j] == 'k') totalk++;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!visited[i][j] && board[i][j]!='#'){
				bfs(i, j);
			}
		}
	}
	printf("%d %d\n", totalk, totalv);
	return 0;
}