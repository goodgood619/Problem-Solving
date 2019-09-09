#include <cstdio>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <string>
#include <string.h>
#include <queue>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
ll dp[100];
int main(){
	int n;
	scanf("%d",&n);
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i <= 80; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	ll ans = (dp[n]+dp[n] + dp[n-1]) * 2;
	printf("%lld\n", ans);
	return 0;
}