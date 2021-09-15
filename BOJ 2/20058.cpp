#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <deque>
using namespace std;
int gox[4] = { 0,0,-1,1};
int goy[4] = { 1,-1,0,0};
void rotate(int x,int y,int l,vector<vector<int>> &board, vector<vector<int>> &tempboard) {
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < l; j++) {
			tempboard[i][j] = board[x + l - 1 - j][y + i];
		}
	}

	for (int i = 0; i < l; i++) {
		for (int j = 0; j < l; j++) {
			board[x + i][y + j] = tempboard[i][j];
		}
	}
}
int dfs(int x,int y,int n,vector<vector<int>> &board, vector<vector<bool>> &visited) {
	visited[x][y] = true;
	int ret = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + gox[i];
		int ny = y + goy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny] || board[nx][ny] <= 0) continue;
		ret += dfs(nx, ny, n, board, visited);
	}
	return ret;
}
int main() {
	int n, q;
	scanf("%d%d", &n, &q);
	vector<vector<int>> board,tempboard;
	n = (1 << n);
	board.assign(n, vector<int>(n, 0));
	tempboard.assign(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %d", &board[i][j]);
		}
	}


	for (int i = 0; i < q; i++) {
		int l;
		scanf("%d", &l);

		
		l = (1 << l);

		for (int i = 0; i < n; i+=l) {
			for (int j = 0; j < n; j += l) {
				rotate(i, j, l, board, tempboard);
			}
		}

		vector<vector<bool>> icemeltcheck;

		icemeltcheck.assign(n, vector<bool>(n, false));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == 0) continue;
				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int nx = i + gox[k];
					int ny = j + goy[k];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n || board[nx][ny] == 0) continue;
					cnt++;
				}
				if (cnt < 3) icemeltcheck[i][j] = true;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (icemeltcheck[i][j]) board[i][j]--;
			}
		}

	}

	int cnt = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cnt += board[i][j];
		}
	}

	vector<vector<bool>> visited;
	visited.assign(n, vector<bool>(n, false));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && board[i][j] > 0) {
				ans = max(ans, dfs(i, j, n,board, visited));
			}
		}
	}

	printf("%d\n%d\n", cnt, ans);
	return 0;
}
