#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll dp[105];
int t;
int main(){
	scanf("%d", &t);
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;
	for (int i = 6; i <= 100; i++) {
		dp[i] = dp[i - 1] + dp[i - 5];
	}
	while (t--){
		int n;
		scanf("%d", &n);
		printf("%lld\n", dp[n]);
	}
	return 0;
}