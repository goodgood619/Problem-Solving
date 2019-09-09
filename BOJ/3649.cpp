#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <map>
#include <string>
#include <iostream>
#include <math.h>
#include <stack>
#include <string.h>
using namespace std;
typedef long long ll;
ll x, same;
ll rego[1000005];
#define gob 10000000
int main() {
	while (~scanf("%lld", &x)) {
		memset(rego, 0, sizeof(rego));
		int n;
		ll ans1 = 0;
		ll ans2 = 0;
		ll diff = -100000;
		bool check = false;
		scanf("%d", &n);
		x *= gob;
		same = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%lld", &rego[i]);
			if (rego[i] == x / 2) {
				same++;
			}
		}
		sort(rego + 1, rego + n + 1);
		for (int i = 1; i <= n; i++) {
			ll piece = rego[i];
			for (ll j = gob; j <= x; j += gob) {
				ll *idx = lower_bound(rego + 1, rego + n + 1, x - piece);
				if (*idx == piece&& same == 1) continue; // 반인 조각이 한개면 lower_bound로 같은놈찾을수도 있으니까 ㅇㅇ
				if (*idx + piece == x) {
					check = true;
					if (diff < abs(*idx - piece)) {
						diff = abs(*idx - piece);
						ans1 = min(*idx, piece);
						ans2 = max(*idx, piece);
					}
				}
			}
		}
		if (check) printf("yes %lld %lld\n", ans1, ans2);
		else printf("danger\n");
	}
	return 0;
}