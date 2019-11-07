#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
bool visited[101][101][2];
struct pos {
	int x;
	int y;
	int sword;
	int dist;
};
void bfs(int x, int y,int n,int m,int t,int &ans,int **board) {
	queue<pos> q;
	q.push({ x,y,0,0 });
	visited[x][y][0] = true;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int sword = q.front().sword;
		int dist = q.front().dist;
		if (x == n && y == m) {
			ans = min(ans, dist);
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i], ny = y + goy[i];
			if (nx<1 || nx>n || ny<1 || ny>m || visited[nx][ny][sword]) continue;
			else {
				if (sword == 0 && !visited[nx][ny][sword] && board[nx][ny] == 0) {
					visited[nx][ny][sword] = true;
					q.push({ nx,ny,sword,dist + 1 });
				}
				else if (sword == 0 && !visited[nx][ny][sword] && board[nx][ny] == 2) {
					visited[nx][ny][sword + 1] = true;
					q.push({ nx,ny,sword+1,dist + 1 });
				}
				else if (sword == 1) {
					if (!visited[nx][ny][sword]) {
						visited[nx][ny][sword] = true;
						q.push({ nx,ny,sword,dist + 1 });
					}
				}
			}
		}
	}
}
int main()
{
	int n, m, t, ans = 1e9;
	scanf("%d%d%d", &n, &m, &t);
	int **board = new int*[n + 1];
	for (int i = 1; i <= n; i++) board[i] = new int[m + 1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	bfs(1, 1,n,m,t,ans,board);
	ans > t ? printf("Fail") : printf("%d\n", ans);
	for (int i = 1; i <= n; i++) delete[] board[i];
	delete[] board;
	return 0;
}