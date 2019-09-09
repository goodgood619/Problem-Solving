#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
char board[7][90];
char word[17];
int k = 0;
int main(){
	scanf("%s", word);
	int length = strlen(word);
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 78; j++) {
			board[i][j] = '.';
			if (i == 1) {
				if (j % 4 == 3) board[i][j] = '#';
			}
			else if (i == 2) {
				if (j % 2 == 0) board[i][j] = '#';
			}
			else if (i == 3) {
				if (j % 4 == 1 || j % 4 == 3) board[i][j] = '#';
			}
			else if (i == 4) {
				if (j % 2 == 0) board[i][j] = '#';
			}
			else if (i == 5) {
				if (j % 4 == 3) board[i][j] = '#';
			}
		}
	}

	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= length * 4 + 1; j++) {
			if (i == 1) {
				if (j % 4 == 3 && (j / 4) % 3 == 2) {
					board[i][j] = '*';
				}
			}
			else if (i == 2){
				if (j % 4 == 3 && (j / 4) % 3 == 2) {
					board[i][j - 1] = '*';
					board[i][j + 1] = '*';
				}
			}
			else if (i == 3) {
				if (j % 4 == 3 && (j / 4) % 3 == 2) {
					board[i][j - 2] = '*';
					board[i][j + 2] = '*';
				}
				if (j % 4 == 3) board[i][j] = word[k++];
			}
			else if (i == 4) {
				if (j % 4 == 3 && (j / 4) % 3 == 2) {
					board[i][j - 1] = '*';
					board[i][j + 1] = '*';
				}
			}
			else if (i == 5) {
				if (j % 4 == 3 && (j / 4) % 3 == 2) {
					board[i][j] = '*';
				}
			}
		}
	}
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= length * 4 + 1; j++) {
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
	return 0;
}