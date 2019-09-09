#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int dp[17][17];
int board[17][17];
int n, m, k,idx,idy;
int go1(int x, int y){
	if (x<0 || x>idx || y<0 || y>idy) return 0;
	if (x == idx && y == idy) return 1;
	int &ret = dp[x][y];
	if (ret != -1) return ret;
	ret = 0;
	ret = go1(x + 1, y)+go1(x, y + 1);
	return ret;
}
int go2(int x, int y) {
	if (x<0 || x>n || y<0 || y>m) return 0;
	if (x == n && y == m) return 1;
	int &ret = dp[x][y];
	if (ret != -1) return ret;
	ret = 0;
	return ret = go2(x + 1, y) + go2(x, y + 1);
}
int main(){
	scanf("%d%d%d", &n, &m, &k);
	if (k != 0) {
		memset(dp, -1, sizeof(dp));
		int p = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				board[i][j] = p;
				p++;
				if (k == board[i][j]) {
					idx = i;
					idy = j;
				}
			}
		}
		int ans1 = go1(1, 1);
		int ans2 = go2(idx, idy);
		printf("%d\n", ans1*ans2);
	}
	else if(k==0){
		memset(dp, -1, sizeof(dp));
		printf("%d\n",go2(1, 1));
	}
	return 0;
}