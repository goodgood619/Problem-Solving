#include <bits/stdc++.h>
using namespace std;
int go(int k,vector<int> &coin,int *dp) {
	if (k == 0) return 0;
	if (k < 0) return 1e9;
	int &ret = dp[k];
	if (ret != -1) return ret;
	ret = 1e9;
	for (int i = 0; i < coin.size(); i++) {
		if (k - coin[i] >= 0) {
			ret = min(ret, go(k - coin[i], coin, dp) + 1);
		}
	}
	return ret;
}
int main() {
	int n;
	scanf("%d", &n);
	vector<int> coin;
	int idx = -1;
	for (int i = 1;i*i<=n; i++) {
		coin.push_back(i*i);
		idx = i;
	}
	int *dp = new int[n+1];
	for (int i = 0; i <= n; i++) dp[i] = -1;
	printf("%d\n", go(n, coin, dp));
	delete[] dp;
	return 0;
}