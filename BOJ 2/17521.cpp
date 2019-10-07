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
typedef pair<double, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { -1,0,1,0 };
int goy[4] = { 0,1,0,-1 };
void go(int bank[], int here, int depth, ll curmoney, ll coin, ll& ans) {
	if (here == depth) {
		ans = max(ans, curmoney);
		return;
	}
	//사거나 팔거나,안사거나
	if (coin > 0) {
		//팔거나, 살수있다,아무것도 안할수도 있다.
		ll tobuy = curmoney / bank[here];
		go(bank, here + 1, depth, curmoney + coin * bank[here], 0, ans);
		go(bank, here + 1, depth, curmoney - tobuy * bank[here], coin + tobuy, ans);
		go(bank, here + 1, depth, curmoney, coin, ans);
	}
	else if (coin == 0) {
		//돈이 있다면 사거나, 아무것도 안할수도 있다.
		ll tobuy = curmoney / bank[here];
		go(bank, here + 1, depth, curmoney - tobuy * bank[here], coin + tobuy, ans);
		go(bank, here + 1, depth, curmoney, coin, ans);
	}
}
int main() {
	int n;
	ll w;
	scanf("%d%lld", &n, &w);
	ll ans = w;
	int* bank = new int[n + 1];
	for (int i = 0; i < n; i++) {
		scanf(" %d", &bank[i]);
	}
	ll rest = w / bank[0];
	go(bank, 1, n, w - rest * bank[0], rest, ans); //사거나
	go(bank, 1, n, w, 0, ans); //안사거나
	printf("%lld\n", ans);
	return 0;
}