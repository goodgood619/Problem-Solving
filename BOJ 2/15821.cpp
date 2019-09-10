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
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
vector<ll> v;
int n, k;
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		int angle;
		scanf("%d", &angle);
		ll dist = 0;
		for (int j = 1; j <= angle; j++) {
			ll x, y;
			scanf(" %lld %lld", &x, &y);
			dist = max(dist, (ll)(x*x) + y * y);
		}
		v.push_back(dist);
	}
	sort(v.begin(), v.end());
	printf("%lld.00\n", v[k - 1]);
	return 0;
}