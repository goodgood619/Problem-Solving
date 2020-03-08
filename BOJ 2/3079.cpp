#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
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
typedef pair<int, pair<int, int>> PP;
typedef pair<pair<string, int>, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int main() {
    ll n,m;
    vector<int> v;
	scanf("%lld%lld", &n, &m);
	for (int i = 1; i <= n; i++) {
		ll num;
		scanf("%lld", &num);
		v.push_back(num);
	}
	ll left = 0;
	ll right = 1e18;
	while (left <= right) {
		ll mid = (left + right) / 2;
		long long cnt = 0;
		for (int i = 0; i < v.size(); i++) {
			cnt += (mid / v[i]);
			if (cnt >= m) break;
		}
		if (cnt < m) left = mid + 1;
		else right = mid - 1;
	}
	printf("%lld\n", left);
	return 0;
}