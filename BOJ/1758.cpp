#include <stdio.h>
#include <algorithm>
using namespace std;
long long dp[100010];
long long sum;
long long arr[100010];
long long arr2[100010];
int n;
int main() {
	scanf("%d", &n);
	for (int i = 0; i <n; i++)
		scanf("%lld", &arr[i]);
	sort(arr, arr + n);
	for (int i = n - 1,j=0; i >= 0; i--,j++)
		arr2[j]= arr[i];

	for (int i = 0, j = n - 1; i <=j; i++, j--) {
		dp[i] = arr2[i] - (i + 1 - 1);
		dp[j] = arr2[j] - (j + 1 - 1);
		if (dp[i] < 0)
			dp[i] = 0;
		if (dp[j] < 0)
			dp[j] = 0;

	}
	for (int i = 0; i < n; i++) {
		sum += dp[i];
	}
	printf("%lld\n", sum);
	return 0;
}