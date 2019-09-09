#include <stdio.h>
#include <algorithm>
using namespace std;
int arr[1001];
int n,ans;
int dp[1001];
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);

	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++){
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[j]+1, dp[i]);
			}
		}
		ans = max(dp[i], ans);
	}
	printf("%d\n", ans);
	return 0;
}