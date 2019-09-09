#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[310][310];
int dp[310][310];
int n, m, t, i, j, x, y,sum;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			scanf("%d", &arr[i][j]);
	}
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d%d", &i, &j, &x, &y);
		for (int a = i; a <= x; a++) {
			for (int b = j; b<= y; b++) {
				sum += arr[a][b];
			}
		}
		printf("%d\n", sum);
		sum = 0;
	}
	return 0;
}