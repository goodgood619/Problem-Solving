#include <cstdio>
#include <algorithm>
using namespace std;
int board[1001][1001];
int ans[1001];
int n;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %d", &board[i][j]);
		}
	}
	int sum1 = board[1][2];
	int sum2 = board[2][3];
	int sum3 = board[1][3];
	int total = (sum1 + sum2 + sum3)/2;
	ans[1] = total - sum2;
	for (int i = 2; i <= n; i++) {
		ans[i] = board[1][i] - ans[1];
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	return 0;
}