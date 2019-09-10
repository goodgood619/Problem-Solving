#include <cstdio>
#include <algorithm>
using namespace std;
#define mod 1000000009
typedef long long ll;
ll dp[1000005];
int t;
int main(){
	scanf("%d", &t);
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i <= 1000000; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % mod;
	}
	while (t--){
		int n;
		scanf("%d", &n);
		printf("%lld\n", dp[n]);
	}
	return 0;
}
