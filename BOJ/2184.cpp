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
typedef pair<int,int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n, m;
ll dp[1005][1005][2];
ll sum[1005];
vector<ll> v;
ll go(int i, int j, int k) {
	if (i == 1 && j == n + 1) return 0;
	ll &ret = dp[i][j][k];
	if (ret != -1) return ret;

	ret = 1e12;
	ll res = n + 1 - (j - i)-1;
	ll ti = 0;
	if (i - 1 >= 1) {
		if (k == 0) ti = sum[i] - sum[i - 1];
		else ti = sum[j] - sum[i - 1];
		ll total = res * ti;
		ret = min(ret, go(i - 1, j, 0) + total);
	}
	if (j+1 <= n+1) {
		if (k == 0) ti = sum[j + 1] - sum[i];
		else ti = sum[j + 1] - sum[j];
		ll total = ti * res;
		ret = min(ret, go(i, j + 1, 1) + total);
	}
	return ret;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		ll num;
		scanf("%lld", &num);
		v.push_back(num);
	}
	v.push_back(m);
	sort(v.begin(), v.end());
	vector<ll>::iterator it;
	int st = lower_bound(v.begin(), v.end(), m)-v.begin();
	for (int i = 1; i < v.size(); i++) {
		sum[i + 1] = v[i] - v[0];
	}
	memset(dp, -1, sizeof(dp));
	printf("%lld\n", go(st+1,st+1, 0));
	return 0;
}