#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
char board[1005][1005];
bool visited[1005][1005];
int n,idx,idy;
typedef pair <int, int> P;
queue <P> q;
int gox[8] = {0,1,-1,0,1,-1,1,-1};
int goy[8] = {1,0,0,-1,1,-1,-1,1};
void bfs(int x,int y){
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx<1 || nx>n || ny<1 || ny>n || board[nx][ny]=='*'|| board[nx][ny]=='M' || visited[nx][ny]) continue;
			else{
				int curnum = board[x][y] - '0';
				int newnum = board[nx][ny] - '0';
				if (board[nx][ny] == '.'){
					board[nx][ny] = curnum + '0';
					continue;
				}
				if (newnum + curnum >= 10) { board[nx][ny] = 'M';}
				else board[nx][ny] = curnum + newnum+'0';
			}
		}
		board[x][y] = '*';
	}
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %c", &board[i][j]);
			int num=board[i][j] - '0';
			if (num >= 1 && num <= 9){
				visited[i][j] = true;
				q.push({ i,j });
				if (idx == 0 && idy == 0) {
					idx = i;
					idy = j;
				}
			}
		}
	}
	bfs(idx,idy);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (board[i][j] == '.') board[i][j] = '0';
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
	return 0;
}