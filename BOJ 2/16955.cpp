#include <cstdio>
#include <cstdint>
using namespace std;
typedef int32_t Int;
typedef int64_t ll;
char board[10][10];
int gox[8] = {0,1,-1,0,1,1,-1,-1};
int goy[8] = {1,0,0,-1,1,-1,1,-1};
bool check() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (board[i][j] != 'X') continue;

			for (int k = 0; k < 8; k++) {
				int x = i, y = j,cnt=1;
				while (true) {
					int nx = x + gox[k], ny = y + goy[k];
					if (nx < 0 || nx >= 10 || ny < 0 || ny >= 10 || board[nx][ny] == '.' || board[nx][ny] == 'O') break;
					cnt++;
					x = nx, y = ny;
				}
				if (cnt >= 5) return true;
			}
		}
	}
	return false;
}
int main() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			scanf(" %c", &board[i][j]);
		}
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (board[i][j] == '.') {
				board[i][j] = 'X';
				if (check()) {
					printf("1");
					return 0;
				}
				board[i][j] = '.';
			}
		}
	}
	printf("0");
	return 0;
}