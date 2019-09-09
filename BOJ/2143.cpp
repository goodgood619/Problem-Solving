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
int t,n,m;
ll arr[1005];
ll arr2[1005];
int main() {
	scanf("%d", &t);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &arr[i]);
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%lld", &arr2[i]);
	}
	vector<ll> v1, v2;
	for (int i = 1; i <= n; i++) {
		ll sum = 0;
		for (int j = i; j <= n; j++) {
			sum += arr[j];
			v1.push_back(sum);
		}
	}
	for (int i = 1; i <= m; i++) {
		ll sum = 0;
		for (int j = i; j <= m; j++) {
			sum += arr2[j];
			v2.push_back(sum);
		}
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	vector<ll>::iterator it,it2;
	ll cnt = 0;
	for (int i = 0; i < v1.size(); i++) {
		it = lower_bound(v2.begin(), v2.end(), t - v1[i]);
		it2 = upper_bound(v2.begin(), v2.end(), t - v1[i]);
		if (*it + v1[i]==t) {
			cnt += (it2 - it);
		}
	}
	printf("%lld\n", cnt);
	return 0;
}