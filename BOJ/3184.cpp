#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
char board[255][255];
int totalsheep,totalwolf,sheep,wolf,n,m;
typedef pair <int, int> P;
int gox[4] = {0,1,-1,0};
int goy[4] = {1,0,0,-1};
bool visited[255][255];
// o:양 v:늑대, o가 v보다 크면 v모두 죽음 반대면 o가 전부죽음 이건 펜스안에서만 가능, .은 뭐 이동경로, #은 벽 애초에 벽이 없어도 가능
void bfs(int x, int y) {
	queue <P> q;
	q.push({ x,y });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++){
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx<1 || nx>n || ny<1 || ny>m || visited[nx][ny] || board[nx][ny] == '#') continue;
			else if (!visited[nx][ny]) {
				visited[nx][ny] = true;
				if (board[nx][ny] == 'o') sheep++;
				else if (board[nx][ny] == 'v') wolf++;
				q.push({ nx,ny });
			}
		}

		}

}
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &board[i][j]);
			if (board[i][j] == 'o') totalsheep++;
			else if(board[i][j] == 'v') totalwolf++;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (board[i][j] == '#') continue;
			else if (!visited[i][j]){
				sheep = 0;
				wolf = 0;
				bfs(i, j);
				if (sheep > wolf) {
					totalwolf -= wolf;
				}
				else totalsheep -= sheep;
			}
		}
	}
	printf("%d %d\n", totalsheep, totalwolf);
	return 0;
}