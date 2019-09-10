#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
bool visited[1003][1003][3];
int board[1003][1003];
int gox[4] = {1,-1,0,0};
int goy[4] = {0,0,-1,1};
int n, m, stx, sty, enx,eny;
int dist[1003][1003];
typedef pair<pair<int, int>, bool> P;
queue <P> q;
void bfs(int stx, int sty) {
	visited[stx][sty][1] = true;
	q.push({{ stx,sty }, false});
	dist[stx][sty]= 0;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		bool check = q.front().second;
		if (x == enx && y == eny) break;
		int ok = 0;
		if (check == true) ok = 2;
		else ok = 1;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx<1 || nx>n || ny<1 || ny>m || visited[nx][ny][ok]) continue;
			if (board[nx][ny] == 0){
				if (check) {
					visited[nx][ny][2] = true;
					q.push({ { nx,ny },true});
				}
				else {
					visited[nx][ny][1] = true;
					q.push({ {nx,ny},false });
				}
				dist[nx][ny] = dist[x][y] + 1;
			}
			else if (board[nx][ny] == 1){
				if (check) continue;
				else {
					visited[nx][ny][2] = true;
					q.push({{nx,ny},true });
					dist[nx][ny] = dist[x][y] + 1;
				}
			}
		}
	}
}
int main(){
	scanf("%d%d", &n,&m);
	scanf("%d%d", &stx, &sty);
	scanf("%d%d", &enx, &eny);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %d", &board[i][j]);
		}
	}
	bfs(stx, sty);
	if (!visited[enx][eny][1] && !visited[enx][eny][2]) printf("-1\n");
	else {
		printf("%d\n",dist[enx][eny]);
	}
	return 0;
}