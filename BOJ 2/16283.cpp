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
typedef pair<ll, ll> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[8] = {-1,1,0,0,1,1,-1,-1 };
int goy[8] = {0,0,-1,1,-1,1,1,-1 };
ll a, b, n, w;
int main() {
	scanf("%lld%lld%lld%lld", &a, &b, &n, &w);
	//a*x+b*y=w,x+y=n-> by-ay=w-n -> y=(w-n)/(b-a);
	if (b != a) {
		ll y = (w - a * n) / (b - a);
		if ((w - a * n) % (b - a) != 0) {
			printf("-1\n");
			return 0;
		}
		ll x = n - y;
		if (x <= 0 || y <= 0) printf("-1\n");
		else {
			for (ll i = x + 1; i < y; i++) {
				ll j = n - i;
				if (a*i + b * j == w) {
					printf("-1\n");
					return 0;
				}
			}
			printf("%lld %lld\n", x, y);
		}
	}
	else {
		vector<P> v;
		for (ll i = 1; i <= n - 1; i++) {
			ll y = n - i;
			if (a*i + b * y == w) {
				v.push_back({ i,y });
			}
		}
		if (v.size() >= 2) {
			printf("-1\n");
		}
		else if(v.size()==1)printf("%lld %lld\n", v[0].first, v[0].second);
		else printf("-1\n");
	}
	return 0;
}