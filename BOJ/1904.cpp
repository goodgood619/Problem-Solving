#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int dp[1000005];
int n;
#define mod 15746
int go(int n) {
	if (n == 1) return 1;
	if (n == 2) return 2;
	int &ret = dp[n];
	if (ret != -1) return ret;
	ret = 0;
	ret = go(n - 1)%mod+ go(n - 2)% mod;
	return ret;
}
int main(){
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", go(n)%mod);
	return 0;
}