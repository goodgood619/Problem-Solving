#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair <int, int> P;
queue <P> q;
int n,Maxwater,ans,cnt;
int Minwater = 99999999;
bool visited[101][101];
int spot[101][101];
int gox[4] = {0,1,0,-1};
int goy[4] = {1,0,-1,0};
void bfs(int x, int y){
	visited[x][y] = true;
	q.push({ x,y });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx<1 || nx>n || ny<1 || ny>n || visited[nx][ny]) continue;
			if (!visited[nx][ny]) {
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
	cnt++;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %d", &spot[i][j]);
			Minwater=min(spot[i][j], Minwater);
			Maxwater = max(spot[i][j], Maxwater);
		}
	}
	for (int k = Minwater; k <= Maxwater; k++){
		cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (spot[i][j] <k) visited[i][j] = true;
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (!visited[i][j]) bfs(i, j);
			}
		}
		ans = max(cnt, ans);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (visited[i][j]) visited[i][j] = false;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}