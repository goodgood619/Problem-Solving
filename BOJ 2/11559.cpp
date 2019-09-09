#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
char board[15][8];
bool visited[15][8];
int p,totalcnt,R;
bool check;
int gox[4] = {0,1,-1,0};
int goy[4] = {1,0,0,-1};
typedef pair <int, int> P;
queue <P> q;
P route[80];
P Remove[80];
void bfs(int x,int y){
	memset(route, 0, sizeof(route));
	visited[x][y] = true;
	q.push({ x,y });
	int whatcnt = 1;
	int k = 0;
	route[k].first = x;
	route[k++].second = y;
	while (!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx < 1 || nx>12 || ny < 1 || ny>6 || visited[nx][ny] || board[nx][ny] == '.' || board[x][y] != board[nx][ny]) continue;
			else if (board[x][y] == board[nx][ny]){
				visited[nx][ny] = true;
				q.push({ nx,ny });
				whatcnt++;
				route[k].first = nx;
				route[k++].second = ny;
			}
		}
	}
	if (whatcnt >= 4) check = true;
	if (k >= 4) {
		for (int i = 0; i < k; i++) {
			Remove[R].first = route[i].first;
			Remove[R++].second = route[i].second;
		}
	}
}
void move() {
	for (int i = 0; i < R; i++) {
		int Rx = Remove[i].first;
		int Ry = Remove[i].second;
		board[Rx][Ry] = '.';
	}
	int dot = 0;
	for (int j = 1; j <= 6; j++){
		dot = 0;
		for (int i = 12; i >= 1; i--){
			if (board[i][j] == '.') {
				dot++;
				continue;
			}
			else if(dot>0){
				board[i + dot][j] = board[i][j];
				board[i][j] = '.';
			}
			else if (dot == 0) continue;
		}
	}
}
int main(){
	for (int i = 1; i <= 12; i++) {
		for (int j = 1; j <= 6; j++) {
			scanf(" %c", &board[i][j]);
		}
	}
	while (1){
		memset(Remove, 0, sizeof(Remove));
		memset(visited, false, sizeof(visited));
		check = false;
		for (int i = 12; i >= 1; i--) {
			for (int j = 1; j <= 6; j++) {
				if (board[i][j] == '.') continue;
				else if (!visited[i][j]) {
					bfs(i, j);
				}
			}
		}
		if (!check) break;
		else totalcnt +=1;
		move();
	}
	printf("%d\n", totalcnt);
	return 0;
}