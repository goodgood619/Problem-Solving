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
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
ll x, y;
int main() {
	scanf("%lld%lld", &x, &y);
	double rate = (double)y*100 / x;
	if ((ll)rate >= 99) {
		printf("-1\n");
		return 0;
	}

	ll left = 0;
	ll right = 1e11;
	ll ans = 0;
	while (left <= right) {
		ll mid = (left + right) / 2;
		double newrate = ((double)(y + mid)*100 / (x + mid));
		if ((ll)newrate > (ll)(rate)){
			ans = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	printf("%lld\n",left);
	return 0;
}

