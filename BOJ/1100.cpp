#include <stdio.h>
#include <algorithm>
using namespace std;
char board[9][9];
int main(){
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			scanf(" %c", &board[i][j]);
		}
	}
	bool check = false;
	int cnt = 0;
	for (int i = 0; i < 8; i++){
		if (i != 0) {
			if (!check) check = true;
			else check = false;
		}
		for (int j = 0; j < 8; j++) {
			if (!check) {
				if (board[i][j] == 'F') cnt++;
				check = true;
			}
			else {
				check = false;
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}