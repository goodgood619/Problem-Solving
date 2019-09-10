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
typedef pair<double, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { -1,0,1,0 };
int goy[4] = { 0,1,0,-1 };
int t, Case = 1,n,m,ans;
int board[8][8];
bool visit[65];
void bfs() {
	queue<pair<int, int>> q;
	int temp[8][8] = { 0, };
	bool visited[8][8] = { false, };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 2) {
				q.push({ i,j });
				visited[i][j] = true;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			temp[i][j] = board[i][j];
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] || temp[nx][ny] == 1) continue;
			else if (!visited[nx][ny] && temp[nx][ny] == 0) {
				temp[nx][ny] = 2;
				q.push({ nx,ny });
				visited[nx][ny] = true;
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (temp[i][j] == 0) cnt++;
		}
	}
	ans = max(ans, cnt);
}
void dfs(int index,int cnt) {
	if (index >= n * m) return;
	if (cnt == 3) {
		bfs();
		return;
	}
	for (int i = index; i < n*m; i++) {
		int x = i / m, y = i % m;
		if (!visit[i] && board[x][y]==0) {
			visit[i] = true;
			board[x][y] = 1;
			dfs(index + 1, cnt + 1);
			board[x][y] = 0;
			visit[i] = false;
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %d", &board[i][j]);
		}
	}
	dfs(0, 0);
	printf("%d\n", ans);
	return 0;
}