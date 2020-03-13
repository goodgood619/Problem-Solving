#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <stack>
#include <map>
#include <string>
using namespace std;
typedef int64_t ll;
int main() {
	int n;
	scanf("%d", &n);
	ll* dp = new ll[n+1];
	dp[0] = 1;
	if (n > 0) dp[1] = 1;
	for(int i=2;i<=n;i++) dp[i]=(dp[i-1]+dp[i-2]+1)% 1000000007;
	printf("%lld\n", dp[n]);
	return 0;
}