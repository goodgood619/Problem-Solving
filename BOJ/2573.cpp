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
typedef pair<int, int> P;
typedef pair<pair<int, int>, pair<int, int>> PPP;
using namespace std;
int gox[4] = {0,1,-1,0};
int goy[4] = {1,0,0,-1};
int board[301][301];
bool visited[301][301];
bool ice[301][301];
int n, m;
void dfs(int x, int y) {
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + gox[i];
		int ny = y + goy[i];
		if (nx<1 || nx>n || ny<1 || ny>m || visited[nx][ny] || board[nx][ny] == 0) continue;
		dfs(nx, ny);
	}
}
int make() {
	for (int i = 1;; i++) {
		int zero = 0;
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= m; k++) {
				zero += (board[j][k] == 0);
			}
		}
		if (zero == n * m) break;
		memset(ice, false, sizeof(ice));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (board[i][j] == 0) continue;
				else {
					for (int k = 0; k < 4; k++) {
						int nx = i + gox[k];
						int ny = j + goy[k];
						if (nx<1 || nx>n || ny<1 || ny>m || ice[nx][ny] || board[nx][ny] != 0) continue;
						else if (board[nx][ny] == 0) {
							board[i][j]--;
							if (board[i][j] < 0) board[i][j] = 0;
							ice[i][j] = true;
						}
					}
				}
			}
		}

		int cnt = 0;
		memset(visited, false, sizeof(visited));
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= m; k++) {
				if (!visited[j][k] && board[j][k] != 0) {
					memset(visited, false, sizeof(visited));
					dfs(j, k);
					cnt++;
				}
			}
		}
		if (cnt >= 2) return i;
	}
	return 0;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %d", &board[i][j]);
		}
	}
	printf("%d\n", make());
	return 0;
}