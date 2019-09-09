#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
char board[105][105];
char realboard[350][350];
int dist[105][105];
bool visited[105][105];
int n, m,Max;
typedef pair <int, int> P;
queue <P> q;
int gox[4] = {0,1,-1,0};
int goy[4] = {1,0,0,-1};
void bfs(){
	while (!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx<0 || nx>n + 1 || ny<0 || ny>m + 1 || visited[nx][ny] || board[nx][ny] == '.') continue;
			else if (!visited[nx][ny] && board[nx][ny] == 'T'){
				visited[nx][ny] = true;
				dist[nx][ny] = dist[x][y] + 1;
				Max = max(Max, dist[nx][ny]);
				q.push({nx,ny});
			}
		}
	}
}
int main(){
	for (int i = 0; i <= 103; i++) {
		for (int j = 0; j <= 103; j++) {
			board[i][j] = '.';
		}
	}
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &board[i][j]);
		}
	}
	for (int i = 0; i <= n + 1; i++) {
		for (int j = 0; j <= m + 1; j++){
			if (board[i][j] == '.') q.push({ i,j });
		}
	}
	bfs();
	int p = 1;
	int q = 1;
	bool check = false;
	for (int i = 1; i <= n; i++){
		if (!check) {
			check = true;
			q = 1;
		}
		else {
			p++;
			q = 1;
		}
		for (int j = 1; j <= m; j++){
			if (Max >= 10){
				if (board[i][j] == '.') {
					realboard[p][q++] = '.';
					realboard[p][q++] = '.';
					realboard[p][q++] = '.';
					continue;
				}
				if (dist[i][j] >= 10) {
					char a = dist[i][j] / 10 + '0';
					char b = dist[i][j] % 10 + '0';
					realboard[p][q++] = '.';
					realboard[p][q++] = a;
					realboard[p][q++] = b;
				}
				else if (dist[i][j] >= 1 && dist[i][j] <= 9) {
					char c = dist[i][j] + '0';
					realboard[p][q++] = '.';
					realboard[p][q++] = '.';
					realboard[p][q++] = c;
				}
			}
			else{
				if (board[i][j] == '.') {
					realboard[p][q++] = '.';
					realboard[p][q++] = '.';
					continue;
				}
					char c = dist[i][j] + '0';
					realboard[p][q++] = '.';
					realboard[p][q++] = c;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1;realboard[i][j]!='\0'; j++) {
			printf("%c", realboard[i][j]);
		}
		printf("\n");
	}
	return 0;
}