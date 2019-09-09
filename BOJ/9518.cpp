#include <stdio.h>
#include <algorithm>
using namespace std;
int n, m;
int gox[4] = { -1,0,1,1 };
int goy[4] = { 1,1,1,0 };
char board[51][51];
bool visited[51][51];
bool aksu[51][51];
int ans;
int idx, idy, spotidx, spotidy;
void go(int x, int y) {
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + gox[i];
		int ny = y + goy[i];
		if (nx<1 || nx>n || ny<1 || ny>m) continue;
		if (aksu[nx][ny] || board[nx][ny] == '.' || visited[nx][ny]) continue;
		if (!aksu[nx][ny] && board[nx][ny] == 'o') {
			aksu[nx][ny] = true;
			ans++;
		}
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + (-1)*gox[i];
		int ny = y + (-1)*goy[i];
		if (nx<1 || nx>n || ny<1 || ny>m) continue;
		if (aksu[nx][ny] || board[nx][ny] == '.' || visited[nx][ny]) continue;
		if (!aksu[nx][ny] && board[nx][ny] == 'o') {
			aksu[nx][ny] = true;
			ans++;
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &board[i][j]);
		}
	}
	// .주위에 제일 o많은곳을 찾아서 거기 .점에다가 o넣는게 목적
	int real = 0;
	int realspot = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (board[i][j] == '.') {
				for (int k = 0; k < 4; k++) {
					int nx = i + gox[k];
					int ny = j + goy[k];
					if (nx<1 || nx>n || ny<1 || ny>m) continue;
					if (board[nx][ny] == 'o')
						real++;
				}
				for (int k = 0; k < 4; k++) {
					int nx = i + (-1)*gox[k];
					int ny = j + (-1)*goy[k];
					if (nx<1 || nx>n || ny<1 || ny>m) continue;
					if (board[nx][ny] == 'o')
						real++;
				}
				if (realspot < real) {
					realspot = real;
					spotidx = i;
					spotidy = j;
				}
			}
			real = 0;
		}
	}
	if (spotidx != 0 && spotidy != 0)
		board[spotidx][spotidy] = 'o';
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!visited[i][j] && board[i][j] == 'o')
				go(i, j);
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= m; j++) {
					if (aksu[i][j])aksu[i][j] = false;
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}