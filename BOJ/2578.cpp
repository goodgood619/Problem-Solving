#include <stdio.h>
#include <algorithm>
using namespace std;
int board[6][6];
int soci[6][6];
bool visited[6][6];
bool ok;
int Cnt;
int main() {
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			scanf(" %d", &board[i][j]);
		}
	}
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			scanf(" %d", &soci[i][j]);
		}
	}
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			int num=soci[i][j];
			bool check = false;
			for (int p = 1; p <= 5; p++) {
				for (int q = 1; q <= 5; q++) {
					if (num == board[p][q]) {
						visited[p][q] = true;
						check = true;
						break;
					}
					else continue;
				}
				if (check) break;
			}
			int cnt = 0;
			int bingo = 0;
			for (int p = 1; p <= 5; p++){
				for (int q = 1; q <= 5; q++) {
					if (visited[p][q]) cnt++;
				}
				if (cnt == 5){
					cnt = 0;
					bingo++;
				}
				else cnt = 0;
			}
			cnt = 0;
			for (int p = 1; p <= 5; p++) {
				for (int q = 1; q <= 5; q++) {
					if (visited[q][p]) cnt++;
				}
				if (cnt == 5){
					cnt = 0;
					bingo++;
				}
				else cnt = 0;
			}
			if (visited[1][1] && visited[2][2] && visited[3][3] && visited[4][4] && visited[5][5]) bingo++;
			if (visited[5][1] && visited[4][2] && visited[3][3] && visited[2][4] && visited[1][5]) bingo++;
			if (bingo>=3) {
				ok = true;
				break;
			}
			Cnt++;
		}
		if (ok) break;
	}
	printf("%d\n", Cnt+1);
	return 0;
}