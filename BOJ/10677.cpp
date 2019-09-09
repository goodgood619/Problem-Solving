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
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, Case = 1;
int main() {
	setbuf(stdout, NULL);
	scanf("%d", &t);
	while (t--) {
		ll a, b;
		int change = 0;
		scanf("%lld%lld", &a, &b);
		if (a > b) {
			swap(a, b);
			change = 1;
		}
		int ans = 0, ans2 = 0;
		for (int i = 10; i <= 15000; i++) {
			ll n = a / 100 * i*i+a/10%10*i+a % 10;
			ll left = 10, right = i;
			int ok = 0;
			while (left <= right) {
				ll mid = (left + right) / 2;
				ll n2 = b / 100 * mid*mid + b / 10 % 10 * mid + b % 10;
				if (n == n2) {
					ok = 1;
					ans = mid;
					break;
				}
				else if (n > n2) {
					left = mid + 1;
				}
				else {
					right = mid - 1;
				}
			}
			if (ok) {
				ans2 = i;
				break;
			}
		}
		change?printf("%d %d\n",ans,ans2): printf("%d %d\n", ans2, ans);
	}
	return 0;
}