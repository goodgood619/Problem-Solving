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
vector<PPP> v;
int parent[3005];
int Size[3005];
ll ccw(P A, P B, P C) {
	ll x1 = A.first, y1 = A.second, x2 = B.first, y2 = B.second, x3 = C.first, y3 = C.second;
	return (x1*y2 + x2 * y3 + x3 * y1) - (x2*y1 + x3 * y2 + x1 * y3);
}
bool cross(P A,P B,P C,P D) {
	ll x1 = A.first, y1 = A.second, x2 = B.first, y2 = B.second, x3 = C.first, y3 = C.second, x4 = D.first, y4 = D.second;
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
int find(int u) {
	if (parent[u] == u) return u;
	return parent[u] = find(parent[u]);
}
void uni(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return;
	if (Size[u] < Size[v]) {
		Size[v] += Size[u];
		Size[u] = 0;
		parent[u] = v;
	}
	else {
		Size[u] += Size[v];
		Size[v] = 0;
		parent[v] = u;
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 0; i <= n; i++) Size[i] = 1;
	for (int i = 1; i <= n; i++) {
		ll x1, y1, x2, y2;
		scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
		v.push_back({{ x1,y1 }, { x2,y2 }});
	}
	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			PPP here = v[i], next = v[j];
			ll ccw1 = ccw(here.first,here.second,next.first);
			ll ccw2 = ccw(here.first, here.second, next.second);
			ll ccw3 = ccw(next.first, next.second, here.first);
			ll ccw4 = ccw(next.first, next.second, here.second);
			if (ccw1*ccw2 > 0 || ccw3 * ccw4 > 0) continue;
			else {
				if (ccw1*ccw2 == 0 && ccw3*ccw4 == 0 && !cross(here.first, here.second, next.first, next.second)) continue;
				if (find(i) != find(j)) uni(i, j);
			}
		}
	}
	int cnt = 0,Max=0;
	for (int i = 0; i < n; i++) {
		if (Size[i] != 0) {
			cnt++;
			Max = max(Size[i], Max);
		}
	}
	printf("%d\n%d\n", cnt, Max);
	return 0;
}