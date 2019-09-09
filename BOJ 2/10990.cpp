#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
int n;
char board[250][250];
int main() {
	scanf("%d", &n);
	if (n == 1) printf("*");
	else{
		int x = 1;
		int y = n;
		for (int i = x,j=y;i <= n;i++,j--){
			board[i][j] = '*';
		}
		for (int i = x, j = y; i <= n; i++, j++) {
			board[i][j] = '*';
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n + i - 1; j++) {
				if (board[i][j] == '*') printf("*");
				else printf(" ");
			}
			printf("\n");
		}
	}
	return 0;
}