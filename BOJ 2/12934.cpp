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
ll x, y;
int main() {
	setbuf(stdout, NULL);
	scanf("%lld%lld", &x, &y);
	int idx = 0, no = 0;
	for (ll i = 1;; i++) {
		ll n = i * (i + 1);
		if (n > 2 * (x + y)) {
			no = 1;
			break;
		}
		if (n == 2 * (x + y)) {
			idx = i;
			break;
		}
	}
	if (no) printf("-1\n");
	else {
		int cnt = 0;
		if (x == 0) {
			printf("0\n");
			return 0;
		}
		if (x < idx && x>0) {
			printf("1\n");
			return 0;
		}
		while (true) {
			if (x > idx) {
				x -= idx, idx--;
				cnt++;
			}
			else {
				cnt++;
				break;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
