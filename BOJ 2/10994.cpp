#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <map>
using namespace std;
typedef long long ll;
int n;
char board[400][400];
int main(){
	scanf("%d", &n);
	if (n == 1) printf("*\n");
	else {
		int sx=2 * n - 1;
		int sy = sx;
		board[sx][sy] = '*';
		for (int i = 1; i <= n - 1; i++) {
			int weight = 2 * i;
			int x = sx - weight;
			int y = sy - weight;
			int j = 0;
			for (int k = 1; k <= 2 * weight + 1; k++){
				board[x][y] = '*';
				y++;
			}
			y--;
			for (int k = 1; k <= 2 * weight + 1; k++) {
				board[x][y] = '*';
				x++;
			}
			x--;
			for (int k = 1; k <= 2 * weight + 1; k++) {
				board[x][y] = '*';
				y--;
			}
			y++;
			for (int k = 1; k <= 2 * weight + 1; k++) {
				board[x][y] = '*';
				x--;
			}
			x++;
		}
		for (int i = 1; i <= 4 * n - 3; i++) {
			for (int j = 1; j <= 4 * n - 3; j++) {
				if (board[i][j] == '*') printf("*");
				else printf(" ");
			}
			printf("\n");
		}
	}
	return 0;
}