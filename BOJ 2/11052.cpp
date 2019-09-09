#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int coin[1005];
int profit[1005];
int n;
int dp[1005];
int go(int k){
	int &ret = dp[k];
	if (ret != -1) return ret;
	ret =0;
	for (int i = 1; i <= n; i++){
		if (k - coin[i] >= 0) {
			ret = max(ret, go(k - coin[i]) +profit[i]);
		}
	}
	return ret;
}
int main(){
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) { scanf("%d", &profit[i]);}
	for (int i = 1; i <= n; i++) { coin[i] = i; }
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	go(n);
	printf("%d\n", dp[n]);
	return 0;
}