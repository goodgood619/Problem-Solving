#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
int board[4100][4100];
bool visited[4100][4100];
typedef pair <int, int> P;
int n,cnt;
int gox[4] = {0,1,-1,0};
int goy[4] = {1,0,0,-1};
void bfs(int x,int y){
	queue <P> q;
	q.push({ x,y });
	visited[x][y] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx < 0 || nx >= 4100 || ny < 0 || ny >= 4100 || visited[nx][ny]) continue;
			else if (!visited[nx][ny]) {
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
	cnt++;
}
int main(){
	scanf("%d", &n);
	int startx = 2030;
	int starty = 2030;
	visited[startx][starty] = true;
	for (int i = 1; i <= n; i++){
		char c;
		scanf(" %c", &c);
		int dx = 0;
		int dy = 0;
		if (c == 'N'){
			dx--;
		}
		else if (c == 'S') {
			dx++;
		}
		else if (c == 'E') {
			dy++;
		}
		else if (c == 'W') {
			dy--;
		}
		for (int j = 0; j < 2; j++) {
			startx += dx;
			starty += dy;
			visited[startx][starty] = true;
		}
	}
	for (int i = 0; i < 4100; i++) {
		for (int j = 0; j < 4100; j++) {
			if (visited[i][j]) continue;
			else {
				bfs(i,j);
			}
		}
	}
		printf("%d\n", cnt - 1);
	return 0;
}