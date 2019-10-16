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
ll n, m, Max;
vector<ll> v;
int main() {
	int t;
	scanf("%d", &t);
	int Case = 1;
	while (t--) {
		scanf("%lld%lld", &n, &m);
		v.clear();
		for (int i = 1; i <= n; i++) {
			ll num;
			scanf("%lld", &num);
			v.push_back(num);
			Max = max(num, Max);
		}

		sort(v.begin(), v.end());
		ll left = 0;
		ll right = 1e14;
		while (left <= right) {
			ll mid = (left + right) / 2;
			ll cnt = 0;
			for (int i = 0; i < v.size(); i++) {
				cnt += (mid / v[i]);
			}
			if (cnt < m) left = mid + 1;
			else right = mid - 1;
		}
		printf("#%d %lld\n",Case++,left);
	}
	return 0;
}

