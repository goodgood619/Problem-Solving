#include <stdio.h>
#include <algorithm>
using namespace std;
char board[11][11];
int r, c;
bool ok;
int gox[4] = {-1,0,1,0};
int goy[4] = {0,1,0,-1};
int main(){
	scanf("%d%d", &r, &c);
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			scanf(" %c", &board[i][j]);
		}
	}
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++){
			if (board[i][j] == '.'){
				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int nx = i + gox[k];
					int ny = j + goy[k];
					if (nx<1 || nx>r || ny<1 || ny>c || board[nx][ny] == 'X') continue;
					if (board[nx][ny] == '.') cnt++;
				}
				if (cnt <= 1) {
					ok = true;
					break;
				}
			}
		}
		if (ok) break;
	}
	if (ok) printf("1\n");
	else printf("0\n");
	return 0;
}