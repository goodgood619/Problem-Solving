#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
int n;
typedef long long ll;
#define mod 1000000007
ll dp[1000007];
ll go(int n){
	ll &ret = dp[n];
	if (ret != -1) return ret;
	ret = 0;
	ret = (go(n - 1)%mod + go(n - 2)%mod)%mod;
	return ret;
}
int main(){
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	dp[1] = 1;
	dp[2] = 1;
	printf("%lld\n", go(n) % mod);
	return 0;
}