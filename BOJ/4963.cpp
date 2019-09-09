#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <math.h>
#include <iostream>
#include <string>
using namespace std;
int n, m;
int h = 1;
typedef long long ll;
int gox[8] = {0,1,-1,0,-1,1,-1,1};
int goy[8] = {1,0,0,-1,-1,1,1,-1};
// 1은 땅, 0은 바다, 땅의 경로의 수 그냥 bfs ㅇㅇ
typedef pair<int, int> P;
bool visited[55][55];
int board[55][55];
void bfs(int x,int y){
	visited[x][y] = true;
	queue <P> q;
	q.push({ x,y });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx<1 || nx>n || ny<1 || ny>m || visited[nx][ny] || board[nx][ny] == 0) continue;
			else if (!visited[nx][ny]) {
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
}
int main(){
	while (1) {
		scanf("%d%d", &m, &n);
		if (n == 0 && m == 0) break;
		memset(visited, false, sizeof(visited));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				scanf(" %d", &board[i][j]);
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (!visited[i][j] && board[i][j] == 1) {
					bfs(i, j);
					ans++;
				}
			}
		}
		printf("%d\n", ans);
	}

	return 0;
}