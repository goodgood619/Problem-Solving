#include <stdio.h>
#include <algorithm>
using namespace std;
typedef pair <int, int> P;
P anspo[9]; // 정답이 존재한다면 그 좌표값을 정렬해서 저장하기위한용도
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
char board[3][3];
bool visited[3][3];
int n, m, cnt;
bool ok;
void dfs(int ans, int x, int y, int deep) {
	anspo[cnt++] = P(x, y);
	if (ans == n && deep == m) {
		ok = true;
		printf("%d\n", 1);
		for (int i = 0; i < cnt; i++)
			printf("%d %d\n", anspo[i].first, anspo[i].second);
		return;
	}
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + gox[i];
		int ny = y + goy[i];
		if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;
		if (ok) break; //정답이 이미 잇으면 할필요 X
		if (deep>=m) break; //숫자를 다썻으면 또더이상 할필요X
		if (visited[nx][ny]) continue;
		if (board[x][y] == '+') dfs(ans + (board[nx][ny] - '0'), nx, ny, deep+1);
		else if (board[x][y] == '-') dfs(ans - (board[nx][ny] - '0'), nx, ny, deep+1);
		else dfs(ans, nx, ny, deep);
	}
	visited[x][y] = false;
	cnt--; //이게이해가안되는데, visited해제시켜주는것처럼 해제시켜주는거같음(답이아니니까 그위치값을지울려고)
	return;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			scanf(" %c", &board[i][j]);
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == '+' || board[i][j] == '-') continue;
			cnt = 0;
			anspo[0] = P(i, j); // 시작하는 위치를 저장하고 시작
			if (ok)break;
			dfs(board[i][j] - '0', i, j, 1);
		}
	}
	if (!ok) printf("%d\n", 0);
	return 0;
}