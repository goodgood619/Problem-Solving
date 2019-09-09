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
typedef pair<ll, int> P;
typedef pair<ll, pair<ll, ll>> PP;
typedef pair<pair<string, int>, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
bool ok;
vector<PP> v;
ll n, t;
ll Min = 1e17;
int main() {
	scanf("%lld%lld", &n, &t);
	for (int i = 0; i < n; i++) {
		ll start, interval, cnt;
		scanf("%lld%lld%lld", &start, &interval, &cnt);
		v.push_back({ start,{interval,cnt} });
	}
	for (int i = 0; i < n; i++) {
		ll left = 1;
		ll right = v[i].second.second;
		while (left <= right) {
			ll mid = (left + right) / 2;
			ll curtime = v[i].first + v[i].second.first*(mid - 1);
			if (curtime <t) {
				left= mid + 1;
			}
			else {
				right = mid - 1;
				Min = min(Min, curtime-t);
			}
		}
	}
	if (Min == 1e17) printf("-1\n");
	else printf("%lld\n", Min);
	return 0;
}