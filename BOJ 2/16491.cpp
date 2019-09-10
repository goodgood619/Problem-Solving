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
#define mod 1000000009
typedef pair<ll,ll> P;
typedef pair<pair<ll, ll>, ll> PP;
typedef pair<pair<ll, ll>, pair<ll, ll>> PPP;
int gox[4] = {0,1, -1,0 };
int goy[4] = {1,0, 0,-1 };
int n;
ll ccw(P A, P B, P C) {
	ll x1 = A.first, y1 = A.second, x2 = B.first, y2 = B.second, x3 = C.first, y3 = C.second;
	return (x1*y2 + x2 * y3 + x3 * y1) - (x2*y1 + x3 * y2 + x1 * y3);
}
bool cross(P A, P B, P C, P D) {
	ll x1 = A.first, y1 = A.second, x2 = B.first, y2 = B.second, x3 = C.first, y3 = C.second,x4=D.first,y4=D.second;
	if (x1 == x2 && x2 == x3 && x3 == x4 && x4 == x1) {
		ll maxy = max(y1, y2);
		ll miny = min(y3, y4);
		if (maxy < miny) return false;
		maxy = max(y3, y4);
		miny = min(y1, y2);
		if (maxy < miny) return false;
	}
	else {
		ll maxx = max(x1, x2);
		ll minx = min(x3, x4);
		if (maxx < minx) return false;
		maxx = max(x3, x4);
		minx = min(x1, x2);
		if (maxx < minx) return false;
	}
	return true;
}
int main() {
	scanf("%d", &n);
	vector<PP> robot,place;
	for (int i = 1; i <= n; i++) {
		ll x1, y1;
		scanf("%lld%lld", &x1, &y1);
		robot.push_back({ { x1,y1 },i });
	}
	for (int i = 1; i <= n; i++) {
		ll x1, y1;
		scanf("%lld%lld", &x1, &y1);
		place.push_back({ { x1,y1 },i });
	}
	sort(place.begin(),place.end());
	vector<int> ans;
	do {
		vector<PPP> temp;
		for (int i = 0; i < robot.size(); i++) {
			temp.push_back({robot[i].first,place[i].first});
		}
		int no = 0;
		for (int i = 0; i < temp.size(); i++) {
			for (int j = i + 1; j < temp.size(); j++) {
				ll ccw1 = ccw(temp[i].first, temp[i].second, temp[j].first);
				ll ccw2 = ccw(temp[i].first, temp[i].second, temp[j].second);
				ll ccw3 = ccw(temp[j].first, temp[j].second, temp[i].first);
				ll ccw4 = ccw(temp[j].first, temp[j].second, temp[i].second);
				if (ccw1*ccw2 > 0 || ccw3 * ccw4 > 0) continue;
				else {
					if (cross(temp[i].first, temp[i].second, temp[j].first, temp[j].second)) {
						no = 1;
						break;
					}
				}
			}
			if (no) break;
		}
		if (!no) {
			for (int i = 0; i < robot.size(); i++) {
				ans.push_back(place[i].second);
			}
			break;
		}
	} while (next_permutation(place.begin(), place.end()));

	for (int i = 0; i < ans.size(); i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}