#include <stdio.h>
#include <algorithm>
using namespace std;
long long dp[1010];
int n,cnt,id,j;
int main() {
	scanf("%d", &n);
	dp[1] = 3;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1];
		id = i;
		j = id;
		while (1) {
			dp[i] += j;
			j++;
			cnt++;
			if (cnt == (i + 1))
				break;
		}
		cnt = 0;
	}
	printf("%lld\n", dp[n]);
	return 0;
}