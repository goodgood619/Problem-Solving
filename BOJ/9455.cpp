#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t, n, m;
int board[101][101];
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		int total = 0;
		memset(board, 0, sizeof(board));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				scanf(" %d", &board[i][j]);
			}
		}
		for (int i = n-1; i >= 1; i--) {
			for (int j = 1; j <= m; j++) {
				if (board[i][j] == 0) continue;
				else if(board[i][j]==1){
					int move = 0;
					for (int k = i+1; k <= n; k++) {
						if (board[k][j] == 0) move++;
						else break;
					}
					if (move != 0) {
						board[i + move][j] = 1;
						board[i][j] = 0;
						total += move;
					}
				}
			}
		}
		printf("%d\n", total);
	}
	return 0;
}