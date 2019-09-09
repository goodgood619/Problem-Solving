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
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { -1,0,0,1 };
int goy[4] = { 0,1,-1,0 };
int t;
int main() {
	scanf("%d", &t);
	while (t--) {
		ll sx, sy, ex, ey;
		int n;
		int ans = 0;
		scanf(" %lld%lld%lld%lld", &sx, &sy, &ex, &ey);
		scanf(" %d", &n);
		for (int i = 1; i <= n; i++) {
			ll x, y, r;
			scanf(" %lld%lld%lld", &x, &y, &r);
			ll dist1 = (x - sx)*(x - sx) + (y - sy)*(y - sy);
			ll dist2 = (x - ex)*(x - ex) + (y - ey)*(y - ey);
			ll dist3 = r * r;
			if ((dist1 - dist3)*(dist2 - dist3) <= 0) ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}