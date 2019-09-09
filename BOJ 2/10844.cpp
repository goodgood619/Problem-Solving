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
int t, Case = 1, n;
ll dp[101][10];
ll go(int index,int num) {
	if (index == n) return 1;
	ll &ret = dp[index][num];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < 10; i++) {
		if (abs(num - i) == 1) {
			ret += go(index + 1, i);
			ret %= INF;
		}
	}
	return ret;
}
int main() {
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	ll ans = 0;
	for (int i = 1; i <= 9; i++) {
		ans += go(1, i);
		ans %= INF;
	}
	printf("%lld\n", ans);
	return 0;
}