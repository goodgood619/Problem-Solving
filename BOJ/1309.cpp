#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
int dp[100005];
#define mod 9901
int main(){
	scanf("%d", &n);
	dp[1] = 3;
	dp[2] = 7;
	for (int i = 3; i <= n; i++) {
		dp[i] = (2 * dp[i- 1] + dp[i - 2]) % mod;
	}
	printf("%d\n", dp[n] % mod);
	return 0;
}