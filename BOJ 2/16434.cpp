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
typedef pair<pair<int, int>, pair<int, int>> PP;
typedef pair < ll, pair < ll, ll >> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
using namespace std;
ll n,at;	
vector<PPP> v;
int main() {
	scanf("%lld%lld", &n,&at);
	for (int i = 0; i < n; i++) {
		ll ti, ai, hi;
		scanf("%lld%lld%lld", &ti, &ai, &hi);
		v.push_back({ ti,{ai,hi} });
	}
	ll left = 1,right=1e18;
	while (left <= right) {
		ll mid = (left + right) / 2;
		ll p = mid;
		ll attack = at;
		for (int i = 0; i < v.size(); i++) {
			if (mid <= 0) break;
			if (v[i].first == 2) {
				attack += v[i].second.first;
				mid += v[i].second.second;
				if (mid > p) mid = p;
			}
			else {
				ll mok = v[i].second.second / attack;
				ll modu = v[i].second.second%attack;
				if (modu != 0) mok += 1;
				mid -= (mok - 1)*v[i].second.first;
			}
		}
		if (mid <= 0) left = p + 1;
		else right = p - 1;
	}
	printf("%lld\n", left);
	return 0;
}