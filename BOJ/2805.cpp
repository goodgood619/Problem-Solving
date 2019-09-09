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
int n, k;
int main() {
	scanf("%d%d", &n, &k);
	vector<ll> v;
	for (int i = 1; i <= n; i++) {
		ll num;
		scanf("%lld", &num);
		v.push_back(num);
	}

	sort(v.begin(), v.end());
	ll left = 0;
	ll right = 1e14;
	while (left <= right) {
		ll mid = (left + right) / 2;
		ll sum = 0;
		for (int i = 0; i < v.size(); i++) {
			if (mid < v[i]) sum += (v[i] - mid);
		}
		if (sum >=(ll)k) {
			left = mid + 1;
		}
		else right = mid - 1;
	}
	printf("%lld\n", left-1);
	return 0;
}