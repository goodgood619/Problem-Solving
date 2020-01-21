#include <cstdio>
#include <cstdint>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef int32_t Int;
typedef int64_t ll;
char board[5][9];
bool visited[12];
struct p {
	int x, y;
};
bool check()
{
	if ((board[0][4] - 'A' + 1) + (board[1][3] - 'A' + 1) + (board[2][2] - 'A' + 1) + (board[3][1] - 'A' + 1) != 26) return false;
	if ((board[0][4] - 'A' + 1) + (board[1][5] - 'A' + 1) + (board[2][6] - 'A' + 1) + (board[3][7] - 'A' + 1) != 26) return false;
	if ((board[1][1] - 'A' + 1) + (board[1][3] - 'A' + 1) + (board[1][5] - 'A' + 1) + (board[1][7] - 'A' + 1) != 26) return false;
	if ((board[3][1] - 'A' + 1) + (board[3][3] - 'A' + 1) + (board[3][5] - 'A' + 1) + (board[3][7] - 'A' + 1) != 26) return false;
	if ((board[4][4] - 'A' + 1) + (board[3][3] - 'A' + 1) + (board[2][2] - 'A' + 1) + (board[1][1] - 'A' + 1) != 26) return false;
	if ((board[4][4] - 'A' + 1) + (board[3][5] - 'A' + 1) + (board[2][6] - 'A' + 1) + (board[1][7] - 'A' + 1) != 26) return false;

	return true;
}
void go(int index,int cnt,int depth,vector<p> &v) {
	if (cnt == depth) {
		if (check()) {
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 9; j++) {
					printf("%c", board[i][j]);
				}
				printf("\n");
			}
			exit(0);
		}
		return;
	}

	for (int i = 0; i < 12; i++) {
		if (!visited[i]) {
			visited[i] = true;
			board[v[index].x][v[index].y] = i + 'A';
			go(index + 1, cnt + 1, depth,v);
			board[v[index].x][v[index].y] = '.';
			visited[i] = false;
		}
	}
}
int main(){
	vector<p> pos;
	int cnt = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 9; j++) {
			scanf(" %c", &board[i][j]);
			if (board[i][j] == 'x') {
				cnt++;
				pos.push_back({ i,j });
			}
			else if (board[i][j] != '.') {
				visited[board[i][j] - 'A'] = true;
			}
		}
	}

	go(0, 0,cnt,pos);
	return 0;
}