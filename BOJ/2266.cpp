#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, k;
#define INF 98765432
int dp[501][501];
int go(int n, int k){
	if (n == 0) return 0;
	if (n == 1) return 1;
	if (k == 1) return n;
	int &ret = dp[n][k];
	if (ret != -1) return ret;
	ret = INF;
	// max(깨졌냐,안깨졌냐)+1(i번째층자체에서 시도횟수)
	for (int i = 1; i <n; i++) {
		ret = min(ret, max(go(i - 1, k - 1), go(n - i, k))+1);
	}
	return ret;
}
int main(){
	scanf("%d%d", &n, &k);
	memset(dp, -1, sizeof(dp));
	int ans=go(n, k);
	printf("%d\n", ans);
	return 0;
}