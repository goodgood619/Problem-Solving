#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
int t,n,ans;
int arr[1001];
int dp[1001];
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &arr[i]);
		}
		dp[1] = arr[1];
		ans = dp[1];
		for (int i = 2; i <= n; i++) {
			dp[i] = max(0, dp[i - 1]) + arr[i];
			ans=max(dp[i], ans);
		}
		printf("%d\n", ans);
		memset(arr, 0, sizeof(arr));
		memset(dp, 0, sizeof(dp));
		ans = 0;
	}
	return 0;
}