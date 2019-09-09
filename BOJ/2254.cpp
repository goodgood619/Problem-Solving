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
int n, px, py;
vector<P> v;
ll ccw(P A, P B, P C) {
	ll x1 = A.first, y1 = A.second, x2 = B.first, y2 = B.second, x3 = C.first, y3 = C.second;
	return (x1*y2 + x2 * y3 + x3 * y1) - (x2*y1 + x3 * y2 + x1 * y3);
}
int main() {
	scanf("%d%d%d", &n, &px, &py);
	for (int i = 1; i <= n; i++) {
		ll x, y;
		scanf("%lld%lld", &x, &y);
		v.push_back({ x,y });
	}
	sort(v.begin(), v.end());
	int cnt = 0;
	while (1) {
		if (v.size()<=2) break;
		stack<ll> st, en;
		st.push(0), st.push(1);
		int ptr = 2;
		while (ptr < v.size()) {
			ll second = st.top();
			st.pop();
			ll first = st.top();
			st.pop();
			ll ccw1 = ccw(v[first], v[second], v[ptr]);
			if (ccw1 > 0) {
				st.push(first), st.push(second), st.push(ptr),ptr++;
			}
			else {
				st.push(first);
				if (st.size() == 1) {
					st.push(ptr);
					ptr++;
				}
			}
		}
		en.push(v.size() - 1), en.push(v.size() - 2);
		ptr = v.size() - 3;
		while (ptr >=0) {
			ll second = en.top();
			en.pop();
			ll first = en.top();
			en.pop();
			ll ccw1 = ccw(v[first], v[second], v[ptr]);
			if (ccw1 > 0) {
				en.push(first), en.push(second), en.push(ptr), ptr--;
			}
			else {
				en.push(first);
				if (en.size() == 1) {
					en.push(ptr);
					ptr--;
				}
			}
		}
		vector<ll> temp;
		map<ll, int> m;
		while (!en.empty()) {
			ll here = en.top();
			en.pop();
			if (m.count(here) == 0) {
				m[here] = 1;
				temp.push_back(here);
			}
		}
		while (!st.empty()) {
			ll here = st.top();
			st.pop();
			if (m.count(here) == 0) {
				m[here] = 1;
				temp.push_back(here);
			}
		}
		vector<P> ans;
		int c = 0, cw = 0;
		for (int i = 0; i < temp.size(); i++) {
			int here = temp[i], next = temp[(i + 1) % temp.size()];
			ll ccw1 = ccw(v[here], v[next], { px,py });
			if (ccw1 > 0) cw++;
			else if (ccw1 < 0) c++;
		}
		if (c == temp.size() || cw == temp.size()) {
			for (int i = 0; i < v.size(); i++) {
				int no = 0;
				for (int j = 0; j < temp.size(); j++) {
					if (i == temp[j]) {
						no = 1;
						break;
					}
				}
				if (!no) ans.push_back({ v[i].first,v[i].second });
			}
			v = ans;
			cnt++;
		}
		else break;
	}
	printf("%d\n", cnt);
	return 0;
}