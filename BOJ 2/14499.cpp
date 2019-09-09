#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int gox[5] = {0,0,0,-1,1};
int goy[5] = {0,1,-1,0,0};
// 동 서 북 남
// 1. 위 2: 위 오른 3: 위북 4: 위남 5:위왼 6 아래
int board[22][22];
int n, m, dicex, dicey, cnt;
int dice[7];
void go(int choice) {
	if (choice == 1) {
		int temp = dice[1];
		dice[1] = dice[5];
		dice[5] = dice[6];
		dice[6] = dice[2];
		dice[2] = temp;
	}
	else if (choice == 2){
		int temp = dice[1];
		dice[1] = dice[2];
		dice[2] = dice[6];
		dice[6] = dice[5];
		dice[5] = temp;
	}
	else if (choice == 3) {
		int temp = dice[1];
		dice[1] = dice[4];
		dice[4] = dice[6];
		dice[6] = dice[3];
		dice[3] = temp;
	}
	else if (choice == 4) {
		int temp = dice[1];
		dice[1] = dice[3];
		dice[3] = dice[6];
		dice[6] = dice[4];
		dice[4] = temp;
	}
}
int main(){
	scanf("%d%d%d%d%d", &n, &m, &dicex, &dicey, &cnt);
	for (int i = 0; i <n; i++) {
		for (int j = 0; j <m; j++) {
			scanf(" %d", &board[i][j]);
		}
	}
	for (int i = 1; i <= cnt; i++) {
		int direct;
		scanf("%d", &direct);
		int nx = dicex + gox[direct];
		int ny = dicey + goy[direct];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
		else {
			go(direct);
			if (board[nx][ny] == 0) {
				board[nx][ny] = dice[6];
			}
			else {
				dice[6] = board[nx][ny];
				board[nx][ny] = 0;
			}
			printf("%d\n", dice[1]);
			dicex = nx;
			dicey = ny;
		}
	}
	return 0;
}