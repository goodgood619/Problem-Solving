#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <math.h>
#include <iostream>
#include <string>
#include <climits>
#include <functional>
using namespace std;
#define inf 1000000007
typedef long long ll;

ll arr[505];
ll dp[505][505];
ll sum[505][505];
ll go(int l, int r) {

	if (r <= l) return 0;
	ll&ret = dp[l][r];
	if (ret != -1) return ret;
	ret = 1e18;
	for (int i = l; i <= r; i++) {
		ret = min(ret, go(l, i) + go(i + 1, r) + sum[l][i] + sum[i + 1][r]);
	}
	return ret;
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n;
		scanf("%d", &n);
		memset(dp, -1, sizeof(dp));
		memset(sum, 0, sizeof(sum));
		for (int i = 0; i < n; i++) {
			scanf("%lld", &arr[i]);
		}
		for (int i = 0; i < n; i++) {
			for (int j = i; j < n; j++) {
				if (j == 0) sum[i][j] = arr[j];
				else sum[i][j] = sum[i][j - 1] + arr[j];
			}
		}

		printf("%lld\n", go(0, n - 1));
	}
}