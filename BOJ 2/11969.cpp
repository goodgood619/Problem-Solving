#include <cstdio>
#include <algorithm>
using namespace std;
int sum[100010][4];
int n, m;
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		for (int j = 1; j <= 3; j++) {
			sum[i][j] = sum[i-1][j];
		}
		sum[i][num]++;
	}
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		int ans1 = sum[b][1] - sum[a - 1][1];
		int ans2 = sum[b][2] - sum[a - 1][2];
		int ans3 = sum[b][3] - sum[a - 1][3];
		printf("%d %d %d\n", ans1, ans2, ans3);
	}
	return 0;
}