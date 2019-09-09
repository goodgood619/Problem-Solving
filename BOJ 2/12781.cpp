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
typedef pair < ll, ll > P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
typedef pair < pair < ll, ll > , pair<ll, ll >> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
vector<PPPP> v;
ll ccw(P A, P B, P C) {
	ll x1 = A.first, y1 = A.second, x2 = B.first, y2 = B.second, x3 = C.first, y3 = C.second;
	return (x1*y2 + x2 * y3 + x3 * y1) - (x2*y1 + x3 * y2 + x1 * y3);
}
int main() {
	ll a, b, c, d, e, f, g, h;
	scanf("%lld%lld%lld%lld%lld%lld%lld%lld", &a, &b, &c, &d, &e, &f, &g, &h);
	v.push_back({ { a,b }, {c,d} });
	v.push_back({ {e,f},{g,h} });
	PPPP here = v[0];
	PPPP next = v[1];
	ll ccw1 = ccw(v[0].first, v[0].second, v[1].first);
	ll ccw2 = ccw(v[0].first, v[0].second, v[1].second);
	ll ccw3 = ccw(v[1].first, v[1].second, v[0].first);
	ll ccw4 = ccw(v[1].first, v[1].second, v[0].second);
	if (ccw1*ccw2 < 0 && ccw3*ccw4 < 0) printf("1\n");
	else printf("0\n");
	return 0;
}