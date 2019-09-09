#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair <int, int> P;
queue <P> q;
char board[100][100];
bool visited[100][100];
int gox[4] = {0,1,-1,0};
int goy[4] = {1,0,0,-1};
int m, n,wi,k,p;
int area[100];
int cnt;
void bfs(int x, int y) {
	visited[x][y] = true;
	q.push({ x,y });
	wi++;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx<0 || nx>=n || ny<0 || ny>=m || visited[nx][ny]) continue;
			if (!visited[nx][ny]) {
				visited[nx][ny] = true;
				wi++;
				q.push({ nx,ny });
			}
		}
	}
	cnt++;
}
int main(){
	scanf("%d%d%d", &m, &n, &k);
	for (int i = 1; i <= k; i++) {
		int x, y, u, v;
		scanf("%d%d%d%d", &x, &y, &u, &v);

		for (int i = x; i < u; i++) {
			for (int j = y; j < v; j++) {
				visited[i][j] = true;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j]){
				wi = 0;
				bfs(i, j);
				area[p++] = wi;
			}
		}
	}

	sort(area, area + p);
	printf("%d\n", cnt);
	for (int i = 0; i <p; i++) printf("%d ", area[i]);
	return 0;
}
