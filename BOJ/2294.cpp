#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <list>
#include <climits>
#include <string.h>
#include <deque>
#include <functional>
#include <stack>
using namespace std;
typedef long long ll;
#define INF 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int dp[10001];
int n, k;
vector<int> coin;
int go(int k) {
	if (k == 0) return 0;
	if (k < 0) return 1e9;
	int &ret = dp[k];
	if (ret != -1) return ret;
	ret = 1e9;
	for (int i = 0; i < coin.size(); i++) {
		if (k - coin[i] >= 0) ret = min(ret, go(k - coin[i]) + 1);
	}
	return ret;
}
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		int money;
		scanf("%d", &money);
		coin.push_back(money);
	}
	memset(dp, -1, sizeof(dp));
	int ans = go(k);
	ans == 1e9 ? printf("-1\n") : printf("%d\n", ans);
	return 0;
}