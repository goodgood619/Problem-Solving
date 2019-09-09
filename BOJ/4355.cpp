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
typedef pair<ll, pair<ll, ll>> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
int main() {
	while (1) {
		ll n;
		scanf("%lld", &n);
		if (n == 0) break;
		ll p = n;
		ll mod = 2;
		vector<ll> v;
		vector<pair<ll, ll>> gob;
		while (p > 1) {
			if (p%mod == 0) {
				v.push_back(mod);
				p /= mod;
				mod = 2;
			}
			else mod++;
		}
		sort(v.begin(), v.end());
		ll here = v[0];
		ll sub = v[0];
		if (v.size() == 1) {
			gob.push_back({ here,here / sub });
		}
		else {
			for (int i = 1; i < v.size(); i++) {
				if (sub == v[i]) {
					here *= v[i];
					sub = v[i];
				}
				else {
					gob.push_back({ here,here / sub });
					here = v[i];
					sub = v[i];
				}
			}
			gob.push_back({ here,here / sub });
		}
		ll sum = gob[0].first-gob[0].second;
		for (int i = 1; i < gob.size(); i++) {
			sum *= (gob[i].first - gob[i].second);
		}
		printf("%lld\n", sum);
	}
	return 0;
}