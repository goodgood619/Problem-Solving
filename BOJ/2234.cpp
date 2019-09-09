#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// 8:남 4:동 2:북 1:서 에 벽이 있다 ㅇㅇ
// 3:남 2:동 1:북 0:서
int gox[4] = {0,-1,0,1};
int goy[4] = {-1,0,1,0};
int n, m,roomcnt=1,Maxsize;
int board[55][55];
int Sizenum[2550];
int checknum[55][55];
bool visited[55][55];
typedef pair<int, int> P;
void bfs(int x, int y) {
	queue <P> q;
	q.push({ x,y });
	visited[x][y] = true;
	checknum[x][y] = roomcnt;
	int Max = 1;
	while (!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 3; i>=0; i--){
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx<1 || nx>n || ny<1 || ny>m || visited[nx][ny] || board[x][y] & (1 << i)) continue;
			else if (!visited[nx][ny]) {
				visited[nx][ny] = true;
				checknum[nx][ny] = roomcnt;
				Max++;
				q.push({ nx,ny });
			}
		}
	}
	Sizenum[roomcnt] =Max;
	Maxsize = max(Maxsize, Max);
}
int main() {
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %d", &board[i][j]);
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (!visited[i][j]){
				bfs(i, j);
				roomcnt++;
			}
		}
	}
	printf("%d\n", roomcnt - 1);
	printf("%d\n", Maxsize);
	// 열부터 비교
	int ans = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m-1; j++){
			if (checknum[i][j] == checknum[i][j + 1]) continue;
			else {
				int Max2 = Sizenum[checknum[i][j]] + Sizenum[checknum[i][j+1]];
				ans = max(ans, Max2);
			}
		}
	}
	//행비교
	for (int j = 1; j <= m; j++){
		for (int i = 1; i <= n - 1; i++) {
			if (checknum[i][j] == checknum[i+1][j]) continue;
			else {
				int Max2 = Sizenum[checknum[i][j]] + Sizenum[checknum[i + 1][j]];
				ans = max(ans, Max2);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}