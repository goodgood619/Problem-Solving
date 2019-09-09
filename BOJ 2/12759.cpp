#include <cstdio>
#include <algorithm>
using namespace std;
int board[4][4];
int move(){
	for (int i = 1; i <= 3; i++){
		int one = 0;
		int two = 0;
		for (int j = 1; j <= 3; j++) {
			if (board[i][j] == 1) one++;
			else if (board[i][j] == 2) two++;
			else continue;
		}
		if (one == 3) {
			return 1;
		}
		else if (two == 3) {
			return 2;
		}
	}
	for (int j = 1; j <= 3; j++) {
		int one = 0;
		int two = 0;
		for (int i = 1; i <= 3; i++) {
			if (board[i][j] == 1) one++;
			else if (board[i][j] == 2) two++;
			else continue;
		}
		if (one == 3) {
			return 1;
		}
		else if (two == 3) {
			return 2;
		}
	}

	if (board[1][1] == 1 && board[2][2] == 1 && board[3][3] == 1) return 1;
	else if (board[1][3] == 1 && board[2][2] == 1 && board[3][1] == 1) return 1;
	else if (board[1][1] == 2 && board[2][2] == 2 && board[3][3] == 2) return 2;
	else if (board[1][3] == 2 && board[2][2] == 2 && board[3][1] == 2) return 2;

	return 0;
}
int main(){
	int num;
	int winner = 0;
	scanf("%d", &num);
	bool check = false;
	if (num == 2) check = true;
	else check = false;
	for (int i = 1; i <= 9; i++) {
		int x, y;
		scanf("%d%d",&x, &y);
		if (!check) {
			board[x][y] = 1;
			check = true;
		}
		else {
			board[x][y] = 2;
			check = false;
		}
		int win=move();
		if (win != 0){
			winner = win;
			break;
		}
	}
	printf("%d\n", winner);
	return 0;
}