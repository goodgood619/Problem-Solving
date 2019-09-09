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
typedef pair<ll, pair<ll, ll>> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
int t;
int main() {
		int n,m;
		scanf("%d%d", &n,&m);
		ll sum2 = 0, sum5 = 0,leftsum2=0,leftsum5=0,rightsum2=0,rightsum5=0;
		for (ll i = 2; i <= n; i *= 2) {
			sum2 += (n / i);
		}
		for (ll i = 5; i <= n; i *= 5) {
			sum5 += (n / i);
		}
		for (ll i = 2; i <= n - m; i *= 2) {
			leftsum2 += ((n - m) / i);
		}
		for (ll i = 5; i <= n - m; i *= 5) {
			leftsum5 += ((n - m) / i);
		}
		for (ll i = 2; i <=m; i *= 2) {
			rightsum2 += (m/i);
		}
		for (ll i = 5; i <= m; i *= 5) {
			rightsum5 += (m / i);
		}
		sum2 -= (leftsum2 + rightsum2);
		sum5 -= (leftsum5 + rightsum5);
		printf("%lld\n", min(sum2, sum5));
	return 0;
}