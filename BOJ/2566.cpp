#include <cstdio>
#include <algorithm>
using namespace std;
int board[10][10];
int idx, idy, Max;
int main() {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			scanf(" %d", &board[i][j]);
			if (Max < board[i][j]) {
				Max = board[i][j];
				idx = i;
				idy = j;
			}
		}
	}
	printf("%d\n", Max);
	printf("%d %d\n", idx, idy);
	return 0;
}