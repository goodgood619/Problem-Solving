#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
ll dp[50];
ll go(int n){
	if (n == 0) return 0;
	if (n == 1) return 1;
	ll &ret = dp[n];
	if (ret != -1) return ret;
	ret = go(n - 1) + go(n - 2);
	return ret;
}
int main(){
	int n;
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	printf("%lld\n",go(n));
	return 0;
}