
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
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t;
ll gcd(ll a, ll b) {
	if (a%b == 0) return b;
	return gcd(b%a, a);
}
int main() {
	scanf("%d", &t);
	while (t--) {
		ll k, c;
		scanf("%lld%lld", &k, &c);
		if (c == 1) {
			if (k + 1 > 1e9) {
				printf("IMPOSSIBLE\n");
			}
			else printf("%lld\n", k + 1);
			continue;
		}
		else if (k == 1) {
			printf("1\n");
			continue;
		}
		else if (gcd(k, c) != 1) {
			printf("IMPOSSIBLE\n");
		}
		else {
			// 초기 값 세팅
			ll x1, x2, x3;
			ll y1, y2, y3;
			ll r1, r2, r3, q;
			x1 = 0, x2 = 1, y1 = 1, y2 = 0;
			r1 = c;
			r2 = k;
			while (r1%r2!=0) { //r3가 0이 될때까지 즉, r(i)가 0이 될때까지 계속 돌린다
				q = r1 / r2;
				r3 = r1%r2;
				x3 = x1 - (q*x2);
				y3 = y1 - (q*y2);
				r1 = r2;
				r2 = r3;
				x1 = x2;
				x2 = x3;
				y1 = y2;
				y2 = y3;
			}
			while (y2 < 0) {
				y2 += k;
				x2 -= c;
			}
			if (y2 > 1e9) printf("IMPOSSIBLE\n");
			else printf("%lld\n", y2);
		}
	}
	return 0;
}