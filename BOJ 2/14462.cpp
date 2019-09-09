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
#define mod 1000000009
typedef pair<int, int> P;
typedef pair<pair<ll, ll>, ll> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,1, -1,0 };
int goy[4] = { 1,0, 0,-1 };
int dp[1005][1005];
int n;
int up[1005], down[1005];
int go(int idx1, int idx2) {
	int &ret = dp[idx1][idx2];
	if (ret != -1) return ret;
	if (idx1 == n || idx2 == n) return 0;
	ret = 0;
	ret = max(go(idx1 + 1, idx2), go(idx1, idx2 + 1));
	if (abs(up[idx1] - down[idx2]) <= 4) ret = max(ret, go(idx1 + 1, idx2 + 1) + 1);
	return ret;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf(" %d", &up[i]);
	for (int i = 0; i < n; i++) scanf(" %d", &down[i]);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", go(0, 0));
	return 0;
}