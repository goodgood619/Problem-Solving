#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
char board[51][6][8];
int n,idx,idy;
int cnt = 98765432;
int go(int i, int j){
	int Cnt = 0;
	for (int p = 1; p <= 5; p++) {
		for (int q = 1; q <= 7; q++) {
			if (board[i][p][q] != board[j][p][q])
				Cnt++;
		}
	}
	return Cnt;
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {

		for (int j = 1; j <= 5; j++) {
			for (int k = 1; k <= 7; k++) {
				scanf(" %c", &board[i][j][k]);
			}
		}
	}

	for (int i = 1; i < n; i++){
		int Max = 0;
		for (int j = i + 1; j <= n; j++) {
			Max=go(i, j);
			if (cnt > Max) {
				cnt = Max;
				idx = i;
				idy = j;
			}
		}
	}
	printf("%d %d\n", idx, idy);
	return 0;
}