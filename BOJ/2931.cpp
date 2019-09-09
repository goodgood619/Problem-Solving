#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
#define mod 1000000009
#define lim 1000000000
typedef pair < int, int > P;
typedef pair<pair<int, int>, int> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n, m, sx, sy, tx, ty, ex, ey;
char board[27][27];
bool visited[27][27];
vector<P> t;
char c;
char temp[8] = { '|','-','1','2','3','4' };
bool check(int x, int y, int nx, int ny, int dir) {
	if (board[x][y] == '|') {
		if (dir == 0 || dir == 3) return true;
		if (dir == 1) {
			if (board[nx][ny] == '-' || board[nx][ny] == '1' || board[nx][ny] == '4') return true;
		}
		else if (dir == 2) {
			if (board[nx][ny] == '-' || board[nx][ny] == '2' || board[nx][ny] == '3') return true;
		}
	}
	else if (board[x][y] == '-') {
		if (dir == 1 || dir == 2) return true;
		if (dir == 0) {
			if (board[nx][ny] == '|' || board[nx][ny] == '1' || board[nx][ny] == '2') return true;
		}
		else if (dir == 3) {
			if (board[nx][ny] == '|' || board[nx][ny] == '3' || board[nx][ny] == '4') return true;
		}
	}
	else if (board[x][y] == '+' || board[x][y] == 'M') {
		if (board[nx][ny] == 'Z') return true;
		if (dir == 0) {
			if (board[nx][ny] == '|' || board[nx][ny] == '1' || board[nx][ny] == '2') return true;
		}
		else if (dir == 1) {
			if (board[nx][ny] == '-' || board[nx][ny] == '1' || board[nx][ny] == '4') return true;
		}
		else if (dir == 2) {
			if (board[nx][ny] == '-' || board[nx][ny] == '2' || board[nx][ny] == '3') return true;
		}
		else {
			if (board[nx][ny] == '|' || board[nx][ny] == '3' || board[nx][ny] == '4') return true;
		}
	}
	else if (board[x][y] == '1') {
		if (dir == 2 || dir == 3) return true;
		if (dir == 0) {
			if (board[nx][ny] == '|' || board[nx][ny] == '1' || board[nx][ny] == '2') return true;
		}
		else {
			if (board[nx][ny] == '-' || board[nx][ny] == '1' || board[nx][ny] == '4') return true;
		}
	}
	else if (board[x][y] == '2') {
		if (dir == 1 || dir == 3) return true;
		if (dir == 0) {
			if (board[nx][ny] == '|' || board[nx][ny] == '1' || board[nx][ny] == '2') return true;
		}
		else {
			if (board[nx][ny] == '-' || board[nx][ny] == '2' || board[nx][ny] == '3') return true;
		}
	}
	else if (board[x][y] == '3') {
		if (dir == 0 || dir == 1) return true;
		if (dir == 2) {
			if (board[nx][ny] == '-' || board[nx][ny] == '2' || board[nx][ny] == '3') return true;
		}
		else {
			if (board[nx][ny] == '+' || board[nx][ny] == '3' || board[nx][ny] == '4') return true;
		}
	}
	else if (board[x][y] == '4') {
		if (dir == 0 || dir == 2) return true;
		if (dir == 1) {
			if (board[nx][ny] == '-' || board[nx][ny] == '1' || board[nx][ny] == '4') return true;
		}
		else {
			if (board[nx][ny] == '|' || board[nx][ny] == '3' || board[nx][ny] == '4') return true;
		}
	}
	return false;
}
// 0:동,1:남,2:북,3:서
void dfs(int x, int y, int px, int py, int dir) {
	if (board[x][y] == '.') {
		int cnt = 0;
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx<1 || nx>n || ny<1 || ny>m) continue;
			if (!visited[nx][ny] && board[nx][ny] != '.' && board[nx][ny]!='M' && board[nx][ny]!='Z') {
				cnt++;
			}
		}
		if (cnt == 3) {
			tx = x, ty = y, c = '+';
		}
		t.push_back({ x,y });
		return;
	}
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + gox[i];
		int ny = y + goy[i];
		if (nx<1 || nx>n || ny<1 || ny>m || visited[nx][ny] || check(x, y, nx, ny, i)) continue;
		if (board[x][y] == '+') {
			dfs(nx, ny, x, y, dir); // '+'는 기존 방향으로 유지하면서 이동
		}
		else {
			if (board[x][y] == 'M' && board[nx][ny] == '.') continue;
			dfs(nx, ny, x, y, i); //새롭게 전환되는 방향으로 이동
		}
	}
}

void dfs2(int x, int y, int dir) {
	if (x == ex && y == ey) {
		printf("%d %d %c", tx, ty, board[tx][ty]);
		exit(0);
	}
	if (board[x][y] != '+') visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + gox[i];
		int ny = y + goy[i];
		if (nx<1 || nx>n || ny<1 || ny>m || board[nx][ny] == '.' || board[nx][ny] == '\0' || check(x, y, nx, ny, i)) continue;
		else if (!visited[nx][ny]) {
			if (board[x][y] == '+' && i != dir) continue;
			dfs2(nx, ny, i);
		}
	}

}
int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &board[i][j]);
			if (board[i][j] == 'M') sx = i, sy = j;
			if (board[i][j] == 'Z') ex = i, ey = j;
		}
	}
	dfs(sx, sy, sx, sy, -1);
	if (c != '\0') {
		printf("%d %d %c\n", tx, ty, c);
		return 0;
	}

	for (int i = 0; i < t.size(); i++) {
		for (int j = 0; j < 6; j++) {
			memset(visited, false, sizeof(visited));
			board[t[i].first][t[i].second] = temp[j];
			tx = t[i].first, ty = t[i].second;
			dfs2(sx, sy, -1);
			board[t[i].first][t[i].second] = '\0';
			tx = 0, ty = 0;
		}
	}
	return 0;
}