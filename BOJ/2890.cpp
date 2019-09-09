#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
char board[51][51];
int leng,r,c,k;
int cnt[51];
int teamnum[51];
int score[51];
bool check;
int main() {
	scanf("%d%d", &r, &c);
	for (int i = 1; i<=r; i++) {
		for (int j = 1; j<=c; j++) {
			scanf(" %c", &board[i][j]);
			if (board[i][j] != 'S' && board[i][j] != 'F' && board[i][j] != '.') {
				teamnum[i] = board[i][j] - '0';
			}
		}
	}

	for (int i = 1; i<=r; i++) {
		for (int j =c-1;;j--) {
			if (board[i][j] == '.') cnt[i]++;
			else break;
		}
	}

	int rank = 0;
	for (int i = 1; i <=c; i++) {
		if (check) {
			k++; 
			check = false;
		}
			int num = rank++;
			for (int j = 1; j <= c; j++) {
				if (cnt[j] == c - 2) continue;
				if (cnt[j] == num) {
					score[j] = k+1;
					check = true;
				}
				else continue;
			}
	}
	for (int i = 1; i <= 9;i++){
		for (int j = 1; j <= r; j++){
			if (teamnum[j] == 0) continue;
			if (teamnum[j] == i){
				printf("%d\n", score[j]);
			}
		}
	}
	return 0;
}
