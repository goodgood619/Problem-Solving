#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
ll board[105][105];
int n, m;
ll ans;
ll sum[105][105];
ll hab(int x1, int y1, int x2, int y2) {
	return sum[x2][y2] - sum[x1][y2] - sum[x2][y1] + sum[x1][y1];
}
int main(){
	scanf("%d%d",&n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1lld", &board[i][j]);
			sum[i][j] = board[i][j];
		}
	}
	sum[1][1] = board[1][1];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			sum[i][j] = sum[i][j]+sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++){
			ans = max(ans, sum[i][j]*hab(0,j,n,m)*hab(i,0,n,j));
			ans = max(ans, sum[i][j] * hab(i,0,n,m)*hab(0,j,i,m)); // 문제
			ans = max(ans, sum[n][j]*hab(0,j,i,m)*hab(i,j,n,m));
			ans = max(ans, sum[i][m]*hab(i,0,n,j)*hab(i,j,n,m));
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			ans = max(ans, sum[i][m] * hab(i,0,j,m)*hab(j,0,n,m));
		}
	}
	for (int i = 1; i < m; i++) {
		for (int j = i + 1; j <= m; j++) {
			ans = max(ans, sum[n][i] * hab(0, i, n, j)*hab(0, j, n, m));
		}
	}
	printf("%lld\n", ans);
	return 0;
}