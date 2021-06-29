#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
struct p {
	int x, y;
};
int gox[4] = { 0,1,0,-1 };
int goy[4] = { 1,0,-1,0 };
void bfs(vector<vector<char>>& board, queue<p>& q,vector<vector<bool>> &visited) {
	int n = board.size();
	int m = board[0].size();
	
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] || board[nx][ny] == '#') continue;

			if (board[nx][ny] == '.') {
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}
			else if (board[nx][ny] == '+') {
				int tx = nx;
				int ty = ny;
				while (tx + gox[i] >=0 && tx + gox[i] <n && ty + goy[i] >= 0 && ty+goy[i] < m) {
					if (board[tx][ty] == '#' || board[tx][ty] == '.') {
						break;
					}
					tx += gox[i];
					ty += goy[i];
				}

				if (board[tx][ty] == '#') {
					tx -= gox[i];
					ty -= goy[i];
					if (!visited[tx][ty]) {
						visited[tx][ty] = true;
						q.push({ tx,ty });
					}
				}
				if (board[tx][ty] == '.') {
					if (!visited[tx][ty]) {
						visited[tx][ty] = true;
						q.push({ tx,ty });
					}
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && board[i][j] == '.') {
				printf("P");
			}
			else printf("%c", board[i][j]);
		}
		printf("\n");
	}
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<vector<char>> board;
	vector<vector<bool>> visited;
	board.assign(n, vector<char>(m, ' '));
	visited.assign(n, vector<bool>(m, false));
	queue<p> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %c", &board[i][j]);
			if (board[i][j] == 'W') {
				q.push({ i,j });
			}
		}
	}

	bfs(board, q,visited);

	board.clear();
	visited.clear();

	return 0;
}