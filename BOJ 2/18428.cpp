#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<map>
using namespace std;
typedef long long ll;
int gox[4] = {0,1,-1,0};
int goy[4] = {1,0,0,-1};
void makeObstacle(int index,int cnt,int depth,vector<int> &posobstacle,vector<vector<char>> &board,vector<bool> &visited,
	vector<int> &teacher) {
	int n = board.size();
	if (cnt == depth) {

		bool check = false;
		for (int i = 0; i < teacher.size(); i++) {
			int tx = teacher[i] / n, ty = teacher[i] % n;

			for (int j = 0; j < 4; j++) {
				for (int k = 1;; k++) {
					int nx = tx + k * gox[j], ny = ty + k * goy[j];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n || board[nx][ny] == 'O') break;
					else if (board[nx][ny] == 'S') {
						check = true;
						break;
					}
				}
				if (check) break;
			}
			if (check) break;
		}
		if (check) return;
		else {
			printf("YES\n");
			exit(0);
		}
	}
	for (int i = index; i < posobstacle.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			int x = posobstacle[i] / n, y = posobstacle[i] % n;
			board[x][y] = 'O';
			makeObstacle(i + 1, cnt + 1, depth, posobstacle, board, visited,teacher);
			visited[i] = false;
			board[x][y] = 'X';
		}
	}
}
int main() {
	int n;
	scanf("%d", &n);
	vector<vector<char>> board;
	vector<int> posobstacle,teacher;
	vector<bool> visited;
	board.assign(n, vector<char>(n,'\0'));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %c", &board[i][j]);
			if (board[i][j] == 'X') {
				posobstacle.push_back(i * n + j);
			}
			if (board[i][j] == 'T') {
				teacher.push_back(i * n + j);
			}
		}
	}
	visited.assign(posobstacle.size(), false);
	makeObstacle(0, 0, 3, posobstacle, board,visited,teacher);
	printf("NO");
	return 0;
}