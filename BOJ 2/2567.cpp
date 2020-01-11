#include <cstdio>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
int board[102][102];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		for (int a = x; a < x + 10; a++) {
			for (int b = y; b < y + 10; b++) {
				board[a][b] = 1;
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			if (!board[i][j]) continue;
			if (board[i + 1][j] == 0) cnt++;
			if (board[i - 1][j] == 0) cnt++;
			if (board[i][j - 1] == 0) cnt++;
			if (board[i][j + 1] == 0)cnt++;
 		}
	}
	printf("%d\n", cnt);
	return 0;
}