#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <functional>
#include <queue>
using namespace std;
int board[105][105];
bool visited[10005];
int m, n;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
vector<vector<int>> a;
vector<int> route;
bool ok;
void dfs(int here, int count) {
	visited[here] = true;
	for (int i = 0; i < a[here].size(); i++) {
		int next = a[here][i];
		if (!visited[next]) {
			route.push_back(next);
			dfs(next, count + 1);
		}
		else if (visited[next] && count == m*n) {
			ok = true;
			return;
		}
	}
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(board, 0, sizeof(board));
		memset(visited, false, sizeof(visited));
		a.clear();
		route.clear();
		ok = false;
		scanf("%d%d", &m, &n);
		int cnt = 0;
		a.resize(m*n + 1);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				board[i][j] = cnt;
				cnt++;
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				int here = board[i][j];
				for (int k = 0; k < 4; k++) {
					int nx = i + gox[k];
					int ny = j + goy[k];
					if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
					else {
						int next = board[nx][ny];
						a[here].push_back(next);
					}
				}
			}
		}
		for (int j = 0; j < n; j++) {
			int here = board[0][j];
			int next = board[m - 1][j];
			a[here].push_back(next);
			a[next].push_back(here);
		}
		for (int i = 0; i < m; i++) {
			int here = board[i][0];
			int next = board[i][n - 1];
			a[here].push_back(next);
			a[next].push_back(here);
		}
		route.push_back(0);
		dfs(0, 1);

		if (!ok) printf("-1\n");
		else {
			printf("1\n");
			for (int i = 0; i < route.size(); i++) {
				int here = route[i];
				printf("(%d,%d)\n", here / n, here%n);
			}
		}
	}
	return 0;
}
