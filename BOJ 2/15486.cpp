#include <cstdio>
#include <algorithm>
using namespace std;
int ti[1500005];
int profit[1500005];
int n;
int dp[1500005];
int dp2[1500005];
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &ti[i], &profit[i]);
	}
	int maxday = n;
	int Max = 0;
	for (int i = n; i >= 1; i--){
		if (ti[i] + i - 1 >n) dp[i] = 0;
		else {
			if (ti[i] + i - 1 >= maxday) {
				dp[i] = profit[i] + dp2[ti[i] + i];
			}
			else {
				dp[i] = profit[i] + Max;
			}
		}
		if (Max <= dp[i]) {
			Max = dp[i];
			maxday = i;
		}
		dp2[i] = max(dp2[i], Max);
	}
	printf("%d\n", Max);
	return 0;
}