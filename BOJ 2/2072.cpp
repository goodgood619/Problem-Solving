#include <cstdio>
using namespace std;
int board[20][20];
int gox[4] = {1,-1,1,0};
int goy[4] = {1,1 ,0,1};
bool check(int &ans) {
	//딱 오목만 본다, 
	for (int i = 1; i <= 19; i++) {
		for (int j = 1; j <= 19; j++) {
			for (int k = 0; k < 4; k++) {
				int sx = i - gox[k], sy = j - goy[k];
				if (sx>=1  && sx<=19 && sy>=1 && sy<=19 && board[i][j] == board[sx][sy]) continue;
				if (board[i][j] == 0) continue;
				for (int p = 1; p <= 5; p++) {
					sx = i + gox[k] * p, sy = j + goy[k] * p;
					if (sx < 1 || sx>19 || sy < 1 || sy>19 || board[sx][sy] != board[i][j]) {
						if (p == 5) {
							return true;
						}
						else break;
					}
				}
			}
		}
	}
	return false;
}
int main() {
	int n,ans=-1;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		// 흑
		if (i % 2 == 1) {
			board[x][y] = 1;
			if (check(ans)) {
				ans = i;
				break;
			}
		}
		// 백
		else {
			board[x][y] = 2;
			if (check(ans)) {
				ans = i;
				break;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}