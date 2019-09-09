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
using namespace std;
typedef long long ll;
#define INF 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
int n,cnt=1;
int board[105][105];
int nation[105][105];
bool visited[105][105];
void dfs(int x, int y,int c) {
	visited[x][y] = true;
	nation[x][y] = c;
	for (int i = 0; i < 4; i++) {
		int nx = x + gox[i];
		int ny = y + goy[i];
		if (nx<1 || nx>n || ny<1 || ny>n || visited[nx][ny] || board[nx][ny]==0) continue;
		else if (!visited[nx][ny]) {
			dfs(nx, ny, c);
		}
	}
}
int bfs(int here) {
	queue<P> q;

	int Copy[105][105] = { 0, };
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			Copy[i][j] = board[i][j];
		}
	}
	memset(visited, false, sizeof(visited));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (nation[i][j] == here) {
				q.push({ i,j });
				visited[i][j] = true;
			}
		}
	}
	for (int j = 1;; j++) {
		queue<P> temp;
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + gox[i];
				int ny = y + goy[i];
				if (nation[nx][ny] != here && nation[nx][ny]!=0) return j - 1;
				if (nx<1 || nx>n || ny<1 || ny>n) continue;
				else if (!visited[nx][ny] && Copy[nx][ny] == 0) {
					Copy[nx][ny] = 1;
					visited[nx][ny] = true;
					temp.push({ nx,ny });
				}
			}
		}
		q = temp;



		while (!temp.empty()) {
			int x = temp.front().first;
			int y = temp.front().second;
			temp.pop();
			if (nation[x][y] != 0 && nation[x][y] != here) return j - 1;
		}



	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %d", &board[i][j]);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!visited[i][j] && board[i][j] == 1) {
				dfs(i, j,cnt);
				cnt++;
			}
		}
	}
	int ans = 1e9;
	for (int i = 1; i < cnt; i++) {
		ans = min(ans, bfs(i));
	}
	printf("%d\n", ans);
	return 0;
}