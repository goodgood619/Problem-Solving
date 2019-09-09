#include <cstdio>
#include <algorithm>
using namespace std;
char board[405][405];
int n, posx, posy;
int gox[4] = { 0,1,0,-1 };
int goy[4] = { -1,0,1,0 };
bool check;
void go(int x, int y, int cnt) {
	board[x][y] = '*';
	for (int i = 0; i < 4; i++) {
		if (i == 1) {
			if (!check) {
				for (int j = 1; j <= cnt + 1; j++) {
					int nx = x + gox[i];
					int ny = y + goy[i];
					board[nx][ny] = '*';
					x = nx;
					y = ny;
				}
			}
			else if (check) {
				for (int j = 1; j <= cnt; j++) {
					int nx = x + gox[i];
					int ny = y + goy[i];
					board[nx][ny] = '*';
					x = nx;
					y = ny;
				}
			}
		}
		else {
			if (!check) {
				for (int j = 1; j <= cnt - 1; j++) {
					int nx = x + gox[i];
					int ny = y + goy[i];
					board[nx][ny] = '*';
					x = nx;
					y = ny;
				}
			}
			else if (check) {
				if (i == 2 || i == 3) {
					for (int j = 1; j <= cnt - 2; j++) {
						int nx = x + gox[i];
						int ny = y + goy[i];
						board[nx][ny] = '*';
						x = nx;
						y = ny;
					}
				}
				else if (i == 0) {
					for (int j = 1; j <= cnt - 1; j++) {
						int nx = x + gox[i];
						int ny = y + goy[i];
						board[nx][ny] = '*';
						x = nx;
						y = ny;
					}
				}
			}
		}
	}
	posx = x;
	posy = y - 1;
}
int main() {
	scanf("%d", &n);
	if (n == 1)printf("*");
	else {
		int Size = n;
		int p = n - 1;
		n = 4 * n - 3;
		posx = 1;
		posy = n + 2;
		while (p != 0) {
			if (!check) {
				go(posx, posy, n);
				p--;
				check = true;
				n -= 3;
			}
			else {
				go(posx, posy, n);
				p--;
				n -= 4;
			}
		}
		if (p == 0) {
			board[posx][posy] = '*';
			for (int i = 0; i < 2; i++) {
				for (int j = 1; j <n; j++) {
					int nx = posx + gox[i];
					int ny = posy + goy[i];
					board[nx][ny] = '*';
					posx = nx;
					posy = ny;
				}
			}
			board[posx + 1][posy] = '*';
		}
		for (int i = 1; i <= 4 * Size - 1; i++) {
			for (int j = 3; j <= 4 * Size - 1; j++){
				if (i != 2) {
					if (board[i][j] == '*') printf("%c", board[i][j]);
					else if (board[i][j] == '\0') printf(" ");
				}
				else if (i == 2) {
					if (board[i][j] == '*') printf("%c", board[i][j]);
					else if (board[i][j] == '\0') printf(" ");
					break;
				}
			}
			printf("\n");
		}
	}
	return 0;
}