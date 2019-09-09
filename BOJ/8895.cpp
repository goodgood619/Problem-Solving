#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
ll dp[22][22][22];
int t,n,l,r;
ll go(int n, int l, int r){
	if (l > n || r > n || l <= 0 || r <= 0) return 0;
	if (n == 1) return 1;
	ll &ret = dp[n][l][r];
	if (ret != -1) return ret;
	ret = go(n - 1, l - 1, r) + go(n - 1, l, r - 1) + (n - 2)*go(n - 1, l, r);
	return ret;
} 
int main(){
	scanf("%d", &t);
	while (t--){
		memset(dp, -1, sizeof(dp));
		scanf("%d%d%d", &n, &l, &r);
		ll ans = go(n, l, r);
		printf("%lld\n", ans);
	}
	return 0;
}