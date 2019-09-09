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
#define mod 1000000009
#define lim 1000000000
typedef pair <ll , ll > P;
typedef pair<pair<int, int>, int> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
vector<P> v;
double ccw(P A, P B, P C) {
	ll x1 = A.first, y1 = A.second, x2 = B.first, y2 = B.second, x3 = C.first, y3 = C.second;
	return (x1*y2 + x2 * y3 + x3 * y1) - (x2*y1 + x3 * y2 + x1 * y3);
}
int main(void) {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		ll x, y;
		scanf("%lld%lld", &x, &y);
		v.push_back({ x,y });
	}
	double plustotal = 0, minustotal = 0;
	for (int i = 0; i < v.size(); i++) {
		P here = v[i], next = v[(i + 1) % v.size()];
		double CCW = ccw({0,0}, here, next);
		if (CCW > 0) {
			plustotal += (CCW / 2);
		}
		else {
			double temp = abs(CCW);
			temp /= 2;
			minustotal += temp;
		}
	}
	double total = abs(plustotal - minustotal);
	printf("%.1lf\n", total);
	return 0;
}