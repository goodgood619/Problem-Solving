#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000000
#define mod 1000000009
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,1, -1,0 };
int goy[4] = { 1,0, 0,-1 };
int dfs(int x, int y,int n,int m,int **dist,int **visited, char **board) {
	if (x <=0 || x > n || y <=0 || y > m) return 1; //미로탈출
	int ret = 0;
	visited[x][y] = 1;
	if (board[x][y] == 'U') {
		int nx = x + gox[2];
		int ny = y + goy[2];
		if (!visited[nx][ny]) {
			ret = max(ret, dfs(nx, ny,n,m,dist,visited,board));
		}
		else {
			ret = dist[nx][ny]; // 만약방문되었다면 그 위치값을 전해줌
		}
	}
	else if (board[x][y] == 'D') {
		int nx = x + gox[1];
		int ny = y + goy[1];
		if (!visited[nx][ny]) {
			ret = max(ret, dfs(nx, ny,n,m,dist,visited,board));
		}
		else {
			ret = dist[nx][ny];
		}
	}
	else if (board[x][y] == 'R') {
		int nx = x + gox[0];
		int ny = y + goy[0];
		if (!visited[nx][ny]) {
			ret = max(ret, dfs(nx, ny,n,m,dist,visited,board));
		}
		else {
			ret = dist[nx][ny];
		}
	}
	else if (board[x][y] == 'L') {
		int nx = x + gox[3];
		int ny = y + goy[3];
		if (!visited[nx][ny]) {
			ret = max(ret, dfs(nx, ny,n,m,dist,visited,board));
		}
		else {
			ret = dist[nx][ny];
		}
	}
	dist[x][y] = max(dist[x][y], ret);
	return ret;
}
int main() {
    int n, m;
	scanf("%d%d", &n, &m);
	int **dist = new int*[n+2];
	int **visited = new int*[n+2];
	char **board = new char*[n+2];
	for(int i =0 ;i<=n+1;i++){
        dist[i] = new int[m+2];
        visited[i] = new int[m+2];
        board[i] = new char[m+2];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &board[i][j]);
		}
	}

	for(int i=0;i<=n+1;i++){
        for(int j=0;j<=m+1;j++){
            dist[i][j] = 0;
            visited[i][j] = 0;
        }
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!visited[i][j]) {
				dfs(i, j,n,m,dist,visited,board);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (dist[i][j] == 1) ans++;
		}
	}
	printf("%d\n", ans);
	for(int i =0 ;i<=n+1;i++){
        delete[] dist[i];
        delete[] visited[i];
        delete[] board[i];
	}
	delete[] dist;
	delete[] visited;
	delete[] board;
	return 0;
}