#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define pi 3.141592653589793
typedef long long ll;
ll mod = 1000000000000000000;
ll dp[1003][350];
int n;
ll go(int n, int k){
	if (n - k*pi < 0) return 0;
	if (n - k*pi >= 0 && (n - (k*pi)) <= pi) return 1;
	ll &ret = dp[n][k];
	if (ret != -1) return ret;
	ret = ((go(n - 1, k) % mod + go(n, k + 1) % mod) % mod);
	return ret;
}
int main(){
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	printf("%lld\n",go(n, 0)%mod);
	return 0;
}