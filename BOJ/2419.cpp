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
typedef pair<ll,ll> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
typedef pair<pair<double, double>, pair<double, double>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
ll dp[305][305][2];
int n, m;
vector<ll> v;
ll go(int i, int j, int k,int cnt) {
	if (cnt==0) return 0;
	ll &ret = dp[i][j][k];
	if (ret != -1) return ret;
	ret = 1e10;
	if (i - 1 >= 0) {
		
		if(k==0)ret = min(ret, go(i - 1, j, 0, cnt - 1) + cnt *(v[i]-v[i-1]));
		else ret = min(ret, go(i - 1, j, 0, cnt - 1) + cnt * (v[j] - v[i - 1]));
	}
	if (j + 1 < v.size()) {
		if(k==1)ret = min(ret, go(i, j+1, 1, cnt - 1) + cnt *(v[j+1]-v[j]));
		else ret = min(ret, go(i, j + 1, 1, cnt - 1) + cnt *(v[j+1]-v[i]));
	}
	return ret;
}
int main() {
	scanf("%d%d", &n, &m);
	v.push_back(0);
	for (int i = 1; i <= n; i++) {
		ll num;
		scanf("%lld", &num);
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	ll st = lower_bound(v.begin(), v.end(), 0) - v.begin();
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		memset(dp, -1, sizeof(dp));
		ans = max(ans, i*m - go(st, st, 0, i));
	}
	printf("%lld\n", ans);
	return 0;
}