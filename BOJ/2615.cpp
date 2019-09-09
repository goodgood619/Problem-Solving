#include <stdio.h>
#include <algorithm>
using namespace std;
int board[21][21];
int gox[4] = { -1,0,1,1 };
int goy[4] = { 1,1,1,0 };
int cnt1, cnt2, cnt3, cnt4;
int real;
int ans[19][19];
int a, b;
int move1, move2;
int find(int x, int y) {
	for (int i = 1, k = 1; i <= 19 / 2 || k <= 19 / 2;) {
		if (k == -1 && i == -1)break;
		if (board[x][y] == board[x - i*gox[0]][y - i*goy[0]] && board[x - i*gox[0]][y - i*goy[0]] != 0){
			if (i != -1) {
				cnt1++;
				move1 = i;
				i++;
			}
		}
		else
			i = -1;
		if (board[x][y] == board[x + k*gox[0]][y + k*goy[0]] && board[x + k*gox[0]][y + k*goy[0]] != 0) {
			if (k != -1) {
				cnt1++;
				move2 = k;
				k++;
			}
		}
		else
			k = -1;
	}
	if (cnt1 == 4 && move1 == 0) {
		a = x;
		b = y;
		return board[a][b];
	}
	else if (cnt1 == 4 && move1 != 0) {
		a = x+move1;
		b = y -move1;
		return board[a][b];
	}
	move1 = 0;
	move2 = 0;
	for (int i = 1, k = 1; i <= 19 / 2 || k <= 19 / 2;) {
		if (k == -1 && i == -1)break;
		if (board[x][y] == board[x - i*gox[1]][y - i*goy[1]] && board[x - i*gox[1]][y - i*goy[1]] != 0) {
			if (i != -1) {
				cnt2++;
				move1 = i;
				i++;
			}
		}
		else
			i = -1;
		if (board[x][y] == board[x + k*gox[1]][y + k*goy[1]] && board[x + k*gox[1]][y + k*goy[1]] != 0) {
			if (k != -1) {
				cnt2++;
				move2 = k;
				k++;
			}
		}
		else
			k = -1;
	}
	if (cnt2 == 4 && move1==0) {
		a = x;
		b = y;
		return board[a][b];
	}
	else if (cnt2 == 4 && move1 != 0) {
			a = x;
			b = y - move1;
			return board[a][b];
	}
	move1 = 0;
	move2 = 0;
	for (int i = 1, k = 1; i <= 19 / 2 || k <= 19 / 2;) {
		if (k ==-1 && i == -1)break;
		if (board[x][y] == board[x - i*gox[2]][y - i*goy[2]] && board[x - i*gox[2]][y - i*goy[2]] != 0) {
			if (i != -1) {
				cnt3++;
				move1 = i;
				i++;
			}
		}
		else
			i = -1;
		if (board[x][y] == board[x + k*gox[2]][y + k*goy[2]] && board[x + k*gox[2]][y + k*goy[2]] != 0) {
			if (k != -1) {
				cnt3++;
				move2 = k;
				k++;
			}
		}
		else
			k = -1;
	}
	if (cnt3 == 4 && move1==0) {
		a = x;
		b = y;
		return board[a][b];
	}
	else if (cnt3==4 && move1!=0) {
		a = x - move1;
		b = y - move1;
		return board[a][b];
	}
	move1 = 0;
	move2 = 0;
	for (int i = 1, k = 1; i <= 19 / 2 || k <= 19 / 2;) {
		if (k == -1 && i == -1)break;
		if (board[x][y] == board[x - i*gox[3]][y - i*goy[3]] && board[x - i*gox[3]][y - i*goy[3]] != 0) {
			if (i != -1) {
				cnt4++;
				move1 = i;
				i++;
			}
		}
		else
			i = -1;
		if (board[x][y] == board[x + k*gox[3]][y + k*goy[3]] && board[x + k*gox[3]][y + k*goy[3]] != 0) {
			if (k != -1) {
				cnt4++;
				move2 = k;
				k++;
			}
		}
		else
			k = -1;
	}
	if (cnt4 == 4 && move1==0) {
		a = x;
		b = y;
		return board[a][b];
	}
	else if (cnt4 == 4 && move1 != 0) {
		a = x - move1;
		b = y;
		return board[a][b];
	}
	return 0;
}
int main() {
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			board[i][j] = 0;
		}
	}
	for (int i = 1; i <=19; i++) {
		for (int j = 1; j <=19; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	for (int i = 1; i <=19; i++) {
		for (int j = 1; j <=19; j++) {
			if (board[i][j] != 0) {
				real = find(i, j);
				if (real != 0) {
					printf("%d\n", board[a][b]);
					printf("%d %d\n", a, b);
					break;
				}
				else {
					cnt1 = 0;
					cnt2 = 0;
					cnt3 = 0;
					cnt4 = 0;
					move1 = 0;
					move2 = 0;
				}
			}
		}
		if (real != 0)
			break;
	}
	if (real == 0)
		printf("%d\n", 0);
	return 0;
}