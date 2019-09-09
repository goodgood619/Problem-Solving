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
#define mod 1000000007
typedef pair < ll, ll > P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n, m;
vector<P> v;
ll ccw(P A, P B, P C) {
	ll x1 = A.first, y1 = A.second, x2 = B.first, y2 = B.second, x3 = C.first, y3 = C.second;
	return (x1*y2 + x2 * y3 + x3 * y1) - (x2*y1 + x3 * y2 + x1 * y3);
}
vector<P> f(stack<ll> st, stack<ll> en) {
	vector<P> route, route1, route2;
	int first = st.top();
	st.pop();
	int second = st.top();
	route1.push_back({ second,first });
	st.pop();
	while (!st.empty()) { //아래껍질
		int next = st.top();
		route1.push_back({ next,second });
		second = next;
		st.pop();
	}
	reverse(route1.begin(), route1.end());
	en.pop();
	while (!en.empty()) { // 윗껍질
		int next = en.top();
		route2.push_back({ next,second });
		second = next;
		en.pop();
	}
	ll Max = 0;
	int idx1 = 0, idx2 = 0;
	reverse(route2.begin(), route2.end());
	for (int i = 0; i < route2.size(); i++) route.push_back(route2[i]);
	for (int i = 0; i < route1.size(); i++) route.push_back(route1[i]);
	return route;
}
stack<ll> upconvex(vector<P> v, stack <ll> st) {
	int ptr = 2;
	st.push(0), st.push(1);
	// 0부터 쭉 진행하기(반시계여야 값을 넣을수 있다-> 즉 ccw값이 양수일때)
	while (ptr < v.size()) {
		ll first = st.top();
		st.pop();
		ll second = st.top();
		st.pop();
		ll ccw1 = ccw(v[second], v[first], v[ptr]);
		if (ccw1 > 0) {
			st.push(second);
			st.push(first);
			st.push(ptr);
			ptr++;
		}
		else {
			st.push(second);
			st.push(first); //원상태로 만들고
			st.pop();
			if (st.size() == 1) {
				st.push(ptr);
				ptr++;
			}
		}
	}
	return st;
}
stack<ll> downconvex(vector<P> v, stack<ll> en) {
	int ptr = v.size() - 3;
	en.push(v.size() - 1);
	en.push(v.size() - 2);
	while (ptr >= 0) {
		ll first = en.top();
		en.pop();
		ll second = en.top();
		en.pop();
		ll ccw1 = ccw(v[second], v[first], v[ptr]);
		if (ccw1 > 0) {
			en.push(second);
			en.push(first);
			en.push(ptr);
			ptr--;
		}
		else {
			en.push(second);
			en.push(first); //원상태로 만들고
			en.pop();
			if (en.size() == 1) {
				en.push(ptr);
				ptr--;
			}
		}
	}
	return en;
}
bool check(P A, P B, P C, P D) {
	ll x1 = A.first, y1 = A.second, x2 = B.first, y2 = B.second, x3 = C.first, y3 = C.second, x4 = D.first, y4 = D.second;
	if (x1 == x2 && x2 == x3 && x3 == x4 && x4 == x1) { //y축 그대로
		ll miny = min(y1, y2);
		ll maxy = max(y3, y4);
		if (maxy < miny) return false;
		miny = min(y3, y4);
		maxy = max(y1, y2);
		if (maxy < miny) return false;
	}
	else {
		ll minx = min(x1, x2);
		ll maxx = max(x3, x4);
		if (maxx < minx) return false;
		minx = min(x3, x4);
		maxx = max(x1, x2);
		if (maxx < minx) return false;
	}
	return true;
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		vector<P> v, v2;
		stack<ll> st, en, st2, en2;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) {
			ll x, y;
			scanf("%lld%lld", &x, &y);
			v.push_back({ x,y });
		}
		for (int i = 1; i <= m; i++) {
			ll x, y;
			scanf("%lld%lld", &x, &y);
			v2.push_back({ x,y });
		}
		if (n == 1 && m == 1) {
			printf("YES\n");
			continue;
		}
		sort(v.begin(), v.end());
		sort(v2.begin(), v2.end());
		st = upconvex(v, st);
		en = downconvex(v, en);
		st2 = upconvex(v2, st2);
		en2 = downconvex(v2, en2);
		vector<P> route, route1, route2;
		route1 = f(st, en);
		route2 = f(st2, en2);
		if (route2.size() > m) route2.pop_back();
		if (route1.size() > n) route1.pop_back();
		//이 route1과 route2로 교차판별을 한다 -> 교차한다 -> no
		// 예외 만약 한  convexhull 안에 또  convexhull이 있을때 판별, 점(convexhull을 이루는)과 선분(convexhull)을 비교, 흰색 and 검은색
		int no = 0;
		for (int i = 0; i < route1.size(); i++) {
			P here = route1[i];
			for (int j = 0; j < route2.size(); j++) {
				P next = route2[j];
				ll ccw1 = ccw(v[here.first], v[here.second], v2[next.first]);
				ll ccw2 = ccw(v[here.first], v[here.second], v2[next.second]);
				ll ccw3 = ccw(v2[next.first], v2[next.second], v[here.first]);
				ll ccw4 = ccw(v2[next.first], v2[next.second], v[here.second]);
				if (ccw1*ccw2 > 0 || ccw3 * ccw4 > 0) continue;
				else {
					if (check(v[here.first], v[here.second], v2[next.first], v2[next.second])) { //교차를 한다
						no = 1;
						break;
					}
				}
			}
			if (no) break;
		}
		if (no) {
			printf("NO\n");
			continue;
		}
		bool plu = false;
		bool minus = false;
		for (int i = 0; i < route1.size(); i++) {
			P here = route1[i];
			for (int j = 0; j < route2.size(); j++) {
				int next = route2[j].first;
				ll CCW = ccw(v[here.first], v[here.second], v2[next]);
				if (CCW > 0) {
					if (minus) {
						no = 1;
						break;
					}
					if (!plu) {
						plu = true;
						continue;
					}
				}
				else {
					if (plu) {
						no = 1;
						break;
					}
					if (!minus) {
						minus = true;
						continue;
					}
				}
			}
			if (no) break;
		}
		if (!no && min(n,m)>=3) { //바깥쪽에 존재
			printf("NO\n");
			continue;
		}
		no = 0;
		plu = false, minus = false;
		for (int i = 0; i < route2.size(); i++) {
			P here = route2[i];
			for (int j = 0; j < route1.size(); j++) {
				int next = route1[j].first;
				ll CCW = ccw(v2[here.first], v2[here.second], v[next]);
				if (CCW > 0) {
					if (minus) {
						no = 1;
						break;
					}
					if (!plu) {
						plu = true;
						continue;
					}
				}
				else {
					if (plu) {
						no = 1;
						break;
					}
					if (!minus) {
						minus = true;
						continue;
					}
				}
			}
			if (no) break;
		}
		if (!no && min(n,m)>=3) { // 바깥쪽에 존재
			printf("NO\n");
			continue;
		}
		printf("YES\n");
	}
	return 0;
}