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
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
typedef pair<pair<double, double>, pair<double, double>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
ll dp[300005][2];
int n, s;
P arr[300005];
int h[300005];
ll go(int index,int choose) {
	if (index >= n) return 0;
	ll &ret = dp[index][choose];
	if (ret != -1) return ret;
	ret = max(ret, go(index + 1,0));
	int *idx = lower_bound(h, h + n, arr[index].first + s);
	int next = idx - h;
	ret = max(ret, go(next,1) + arr[index].second);
	return ret;
}
int main() {
	scanf("%d%d", &n, &s);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &arr[i].first, &arr[i].second);
		h[i] = arr[i].first;
	}
	sort(arr, arr + n);
	sort(h, h + n);
	memset(dp, -1, sizeof(dp));
	printf("%lld\n", max(go(0,0),go(0,1)));
	return 0;
}