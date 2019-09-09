#include <cstdio>
#include <algorithm>
using namespace std;
int n, k;
int arr[5005];
int dp[5005];
int dp2[5005];
int dp3[5005];
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		dp[i] = arr[i];
	}
	sort(arr + 1, arr + n + 1);
	int p = 1;
	int cnt = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dp2[j] != 0) continue;
			if (dp[j] == arr[i]) {
				dp2[j] = p;
				if (cnt == k) {
					cnt = 0;
					p++;
				}
				cnt++;
				break;
			}
		}
	}
	int en = 0;
	dp2[0] = -9876543;
	for (int i = 1; i <= n; i++) {
		int *idx = upper_bound(dp3+1, dp3 + en + 1, dp2[i]);
		*idx = dp2[i];
		if (idx == dp3 + en + 1) en++;
	}
	printf("%d\n", n - en);
	return 0;
}