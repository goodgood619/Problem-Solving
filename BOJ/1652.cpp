#include <stdio.h>
#include <algorithm>
using namespace std;
char board[101][101];
int n;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %c", &board[i][j]);
		}
	}
	int cnt = 0;
	int ga= 0;
	int se= 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (board[i][j] == 'X') {
				if (cnt >= 2) {
					ga++;
					cnt = 0;
				}
				else cnt = 0;
			}
			else {
				cnt++;
			}
		}
		if (cnt >= 2) {
			ga++;
			cnt = 0;
		}
		else cnt = 0;
	}
	cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (board[j][i] == 'X') {
				if (cnt >= 2) {
					se++;
					cnt = 0;
				}
				else cnt = 0;
			}
			else {
				cnt++;
			}
		}
		if (cnt >= 2) {
			se++;
			cnt = 0;
		}
		else cnt = 0;
	}
	printf("%d %d\n", ga, se);
	return 0;
}