
#include <cstdio>
#include <algorithm>
using namespace std;
int board[103][103];
int main(){
	for (int i = 1; i <= 4; i++) {
		int x, y, enx, eny;
		scanf("%d%d%d%d", &x, &y, &enx, &eny);
		for (int j = x; j <enx; j++) {
			for (int k = y; k <eny; k++) {
				board[j][k] = 1;
			}
		}
	}

	int sum = 0;
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <=100; j++) {
			if (board[i][j] == 1) sum += 1;
		}
	}
	printf("%d\n", sum);
	return 0;
}