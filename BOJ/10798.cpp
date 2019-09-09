#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
char board[5][15];
int length,Max;
int main(){
	for (int i = 0; i < 5; i++) {
		scanf("%s", board[i]);
		length = strlen(board[i]);
		Max = max(length, Max);
	}
	for (int y = 0; y <Max; y++) {
		for (int x = 0; x < 5; x++){
			if (board[x][y] == '\0') continue;
			printf("%c", board[x][y]);
		}
	}
	return 0;
}