#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <stack>
using namespace std;
int board[1005][1005];
bool visited[2005][2005];
int n,nx,ny;
typedef pair<int,pair<int, int>> P;
P anspo[1005];
int Min = 999999999;
int dist[2005][2005];
int main(){
	scanf("%d", &n);
	int x = 1000;
	int y = 1000;
	int p = 0;
	for (int i = 1; i <= n; i++) {
		char c;
		int num;
		scanf(" %c %d", &c,&num);
		for (int j = 1; j <= num; j++){
			int dx = 0;
			int dy = 0;
			if (c == 'N') dx--;
			else if (c == 'S') dx++;
			else if (c == 'W') dy--;
			else if (c == 'E') dy++;
			nx = x + dx;
			ny = y + dy;
			if (!visited[nx][ny]) {
				visited[nx][ny] = true;
				dist[nx][ny] = p;
				p++;
			}
			else {
				Min = min(p - dist[nx][ny], Min);
				dist[nx][ny] = p;
				p++;
			}
			x = nx;
			y = ny;
		}
	}
	if (Min == 999999999) printf("-1\n");
	else printf("%d\n", Min);
	return 0;
}