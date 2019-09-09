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
#define mod 1000000007
typedef pair<int, ll> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n, s, m,Max;
int dp[1005][105];
int arr[105];
int go(int here, int index) {
	if (index >= n) {
		return here;
	}
	int &ret = dp[here][index];
	if (ret != -1) return ret;
	ret = -1e9;
	if (here + arr[index+1] <= m) {
		ret = max(ret,go(here + arr[index+1], index + 1));
	}
	if (here - arr[index + 1] >= 0) {
		ret = max(ret,go(here - arr[index + 1], index + 1));
	}
	return ret;
}
int main() {
	scanf("%d%d%d", &n, &s, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	memset(dp, -1, sizeof(dp));
	int ans=go(s, 0);
	ans == -1e9 ? printf("-1\n") : printf("%d\n", ans);
	return 0;
}