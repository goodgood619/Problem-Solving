#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
int t,startx,starty,enx,eny,l;
int gox[8] = {1,1,-2,-2,-1,-1,2,2};
int goy[8] = {2,-2,1,-1,2,-2,1,-1};
bool visited[305][305];
int dist[305][305];
typedef pair<int, int> P;
queue <P> q;
void bfs(int x, int y) {
	q.push({ x,y });
	visited[x][y] = true;
	dist[x][y] = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx<0 || nx>l-1 || ny<0 || ny>l-1 || visited[nx][ny]) continue;
			else if (!visited[nx][ny]){
				q.push({ nx,ny });
				visited[nx][ny] = true;
				dist[nx][ny] = dist[x][y] + 1;
			}
		}
	}
}
int main(){
	scanf("%d", &t);
while (t--){
		memset(dist, 0, sizeof(dist));
		memset(visited, false, sizeof(visited));
		scanf("%d", &l);
		scanf("%d%d", &startx, &starty);
		scanf("%d%d", &enx, &eny);
		bfs(startx, starty);

		printf("%d\n", dist[enx][eny]);
	}
	return 0;
}