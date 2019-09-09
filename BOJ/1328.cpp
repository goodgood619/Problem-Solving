#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
ll dp[103][103][103];
int n, l, r;
#define mod 1000000007
ll go(int n, int l, int r) {
	if (l >n || r >n || n == 0 || l <= 0 || r <= 0) return 0;
	if (n == 1) return 1;
	ll &ret = dp[n][l][r];
	if (ret != -1) return ret;
	ret = ((go(n - 1, l - 1, r) % mod) + (go(n - 1, l, r - 1) % mod) + ((go(n - 1, l, r)*(n - 2)) % mod));
	return ret;
}
int main(){
	scanf("%d%d%d", &n, &l, &r);
	memset(dp, -1, sizeof(dp));
	printf("%lld\n", go(n, l, r)%mod);
	return 0;
}