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
typedef pair<pair<int, int>, int> PP;
typedef pair<pair<ll, ll>, pair<ll, ll>> PPP;
int gox[4] = {0,1, -1,0 };
int goy[4] = {1,0, 0,-1 };
int n;
ll ccw(P A, P B, P C) {
	ll x1 = A.first, y1 = A.second, x2 = B.first, y2 = B.second, x3 = C.first, y3 = C.second;
	return (x1*y2 + x2 * y3 + x3 * y1) - (x2*y1 + x3 * y2 + x1 * y3);
}
bool compare(const P &a,const P &b) {
	if (a.second != b.second) return a.second > b.second;
	if (a.first != b.first) return a.first < b.first;
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		vector<P> v;
		for (int i = 1; i <= n; i++) {
			ll x1, y1, x2, y2;
			scanf("%lld%lld", &x1, &y1);
			v.push_back({ x1,y1 });
		}
		sort(v.begin(), v.end());
		stack<ll> up, down;
		up.push(0), up.push(1);
		int ptr = 2;
		while (ptr < v.size()) {
			ll second = up.top();
			up.pop();
			ll first = up.top();
			up.pop();
			ll ccw1 = ccw(v[first], v[second], v[ptr]);
			if (ccw1 > 0) {
				up.push(first), up.push(second), up.push(ptr), ptr++;
			}
			else {
				up.push(first);
				if (up.size() == 1) {
					up.push(ptr);
					ptr++;
				}
			}
		}
		down.push(v.size() - 1), down.push(v.size() - 2), ptr = v.size() - 3;
		while (ptr >= 0) {
			ll second = down.top();
			down.pop();
			ll first = down.top();
			down.pop();
			ll ccw1 = ccw(v[first], v[second], v[ptr]);
			if (ccw1 > 0) {
				down.push(first), down.push(second), down.push(ptr), ptr--;
			}
			else {
				down.push(first);
				if (down.size() == 1) {
					down.push(ptr);
					ptr--;
				}
			}
		}
		map<ll, int> m;
		vector<P> ans,temp;
		int cnt = 0;
		while (!up.empty()) {
			ll here = up.top();
			up.pop();
			if (m.count(here) == 0) {
				m[here] = 1;
				ans.push_back(v[here]);
			}
		}
		reverse(ans.begin(), ans.end());
		while (!down.empty()) {
			ll here = down.top();
			down.pop();
			if (m.count(here) == 0) {
				m[here] = 1;
				temp.push_back(v[here]);
			}
		}
		reverse(temp.begin(), temp.end());
		for (int i = 0; i < temp.size(); i++) {
			ans.push_back(temp[i]);
		}
		reverse(ans.begin(), ans.end());
		ll maxy = -1e9, minx = 1e9,st=-1;
		for (int i = 0; i < ans.size(); i++) {
			if (maxy < ans[i].second) {
				maxy = ans[i].second;
				minx = ans[i].first;
				st = i;
			}
			else if (maxy == ans[i].second) {
				if (minx > ans[i].first) {
					st = i;
					minx = ans[i].first;
				}
			}
		}
		printf("%d\n", ans.size());
		for (int i = st,j=0; j<ans.size();j++) {
			int here = (i+j) % ans.size();
			printf("%lld %lld\n", ans[here].first, ans[here].second);
		}
	}
	return 0;
}