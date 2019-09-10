#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <list>
#include <climits>
#include <string.h>
#include <deque>
#include <functional>
#include <stack>
using namespace std;
typedef long long ll;
#define INF 1000000000
#define mod 1000000007
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { -1,0,1,0 };
int goy[4] = { 0,1,0,-1 };
//0:북,1:동,2:남,3:서
int board[55][55];
bool visited[55][55];
int n, m, dir, sx, sy, cnt;
void dfs(int x, int y, int dir) {
	int p = dir;
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		p -= 1;
		if (p < 0) p = 3;
		int nx = x + gox[p];
		int ny = y + goy[p];
		if (!visited[nx][ny] && board[nx][ny] != 1) {
			cnt++;
			dfs(nx, ny, p);
		}
	}
	//후진!!
	int temp = (dir + 2) % 4;
	int nx = x + gox[temp];
	int ny = y + goy[temp];
	if (board[nx][ny] != 1) {
		dfs(nx, ny, dir);
	}
	printf("%d\n", cnt);
	exit(0);
}
int main() {
	scanf("%d%d", &n, &m);
	scanf("%d%d%d", &sx, &sy, &dir);
	for (int i = 0; i <n; i++) {
		for (int j = 0; j <m; j++) {
			scanf(" %d", &board[i][j]);
		}
	}
	cnt = 1;
	dfs(sx, sy, dir);
	printf("%d\n", cnt);
	return 0;
}