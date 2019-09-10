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
int n, q;
ll arr[400005];
ll temp[200005];
int main() {
	scanf("%d%d", &n,&q);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &arr[i]);
		arr[i + n] = arr[i];
	}
	int ptr = 1;
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ll here = arr[i] * arr[i + 1] * arr[i + 2] * arr[i + 3];
		temp[ptr++] = here;
		ans += here;
	}

	for (int i = 1; i <= q; i++) {
		int a;
		scanf("%d", &a);
		if (a <= 3) {
			ll here1 = temp[a],here2=0,here3=0,here4=0;
			int check2 = 0, check3 = 0, check4 = 0;
			if (a - 1 < 1) {
				check2 = 1;
				here2 = temp[n + a - 1];
			}
			else here2 = temp[a - 1];
			if (a - 2 < 1) {
				check3 = 1;
				here3 = temp[n + a - 2];
			}
			else here3 = temp[a - 2];
			if (a - 3 < 1) {
				check4 = 1;
				here4 = temp[n + a - 3];
			}
			else here4 = temp[a - 3];
			ans = ans - (here1 + here2 + here3 + here4);
			ans = ans + (-here1 - here2 - here3 - here4);
			temp[a] = -here1;
			if (check2) temp[n + a - 1] = -here2;
			else temp[a - 1] = -here2;
			if (check3) temp[n + a - 2] = -here3;
			else temp[a - 2] = -here3;
			if (check4) temp[n + a - 3] = -here4;
			else temp[a - 3] = -here4;
			printf("%lld\n", ans);
		}
		else {
			ll here1 = temp[a], here2 = temp[a - 1], here3 = temp[a - 2], here4 = temp[a - 3];
			ans = ans - (here1 + here2 + here3 + here4);
			ans = ans + (-here1 - here2 - here3 - here4);
			printf("%lld\n", ans);
			temp[a] = -here1, temp[a - 1] = -here2, temp[a - 2] = -here3, temp[a - 3] = -here4;
		}
	}
	return 0;
}