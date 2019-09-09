#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <math.h>
#include <iostream>
#include <string>
using namespace std;
int n;
int h = 1;
char board[400][800];
int main() {
	scanf("%d", &n);
	if (n == 1) printf("*\n");
	else {
		int herex = 1;
		int herey = n;
		// 왼쪽대각선
		for (int i = herex, j = n; i <= n && j >= 1; i++, j--) {
			board[i][j] = '*';
		}
		for (int i = herex, j = n; i <= n && j <= 2 * n - 1; i++, j++) {
			board[i][j] = '*';
		}
		for (int i = n, j = 1; j <= 2 * n - 1; j++) {
			board[i][j] = '*';
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n + i - 1; j++){
				if (board[i][j] != '*') printf(" ");
				else printf("%c", board[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}