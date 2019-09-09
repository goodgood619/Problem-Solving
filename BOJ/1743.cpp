#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
char food[101][101];
bool visited[101][101];
int n, m, k,ans,Ans,cnt;
int dist[101][101];
int gox[4] = { 0,1,0,-1 };
int goy[4] = { 1,0,-1,0 };
typedef pair <int, int> P;
queue <P> q;
/*
int dfs(int x, int y,int cnt) {
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + gox[i];
		int ny = y + goy[i];
		if (nx<1 || nx>n || ny<1 || ny>m || visited[nx][ny] || food[nx][ny] == '\0') continue;
		if (!visited[nx][ny] && food[nx][ny] == '#'){
			visited[nx][ny] = true;
			cnt++;
			ans+=dfs(nx, ny,cnt);
		}
	}
	return ans;
}
*/

void bfs(int x, int y) {
	visited[x][y] = true;
	q.push({ x,y });
	cnt= 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (food[nx][ny] == '\0' || visited[nx][ny] || nx<1 || nx>n || ny<1 || ny>m) continue;
			if (!visited[nx][ny] && food[nx][ny] == '#') {
				visited[nx][ny] = true;
				q.push({ nx,ny });
				cnt++;
				ans = max(ans, cnt);
			}
		}
	}
	ans = max(ans, cnt);
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= k; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		food[u][v] = '#';
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++){
			if (food[i][j] == '#' && !visited[i][j]) {
				bfs(i, j);
				Ans = max(Ans, ans);
				ans = 0;
			}
		}
	}
	printf("%d\n", Ans);
	return 0;
}