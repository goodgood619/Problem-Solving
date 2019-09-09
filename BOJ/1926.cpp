#include <cstdio>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
#include <map>
using namespace std;
int n, m,Max;
int board[505][505];
int gox[4] = {0,1,-1,0};
int goy[4] = {1,0,0,-1};
typedef pair <int, int> P;
queue <P> q;
bool visited[505][505];
void bfs(int x, int y) {
	visited[x][y] = true;
	q.push({ x,y });
	int aa = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx<1 || nx>n || ny<1 || ny>m || visited[nx][ny] || board[nx][ny] == 0) continue;
			if (!visited[nx][ny] && board[nx][ny]==1) {
				visited[nx][ny] = true;
				q.push({ nx,ny });
				aa++;
			}
		}
	}
	Max=max(aa, Max);
}
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %d", &board[i][j]);
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (board[i][j] == 1 && !visited[i][j]) {
				bfs(i,j);
				cnt++;
			}
		}
	}
	printf("%d\n", cnt);
	printf("%d\n", Max);
	return 0;
}