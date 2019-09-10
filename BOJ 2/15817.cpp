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
using namespace std;
typedef long long ll;
#define INF 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n, x;
P coin[105];
int dp[105][10005];
int go(int n, int k) {
	if (k == 0) return 1;
	if (n <= 0) return 0;
	int &ret = dp[n][k];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i <= coin[n].second; i++) {
		if (k - i*coin[n].first >= 0) {
			ret += go(n - 1, k - i*coin[n].first);
		}
	}
	return ret;
}
int main() {
	scanf("%d%d", &n, &x);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &coin[i].first, &coin[i].second);
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", go(n, x));
	return 0;
}
