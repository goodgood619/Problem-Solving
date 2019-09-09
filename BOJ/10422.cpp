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
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t;
int n;
ll dp[5005][5005];
ll go(int x, int y) {
	if (x < y) return 0;
	if (x <0 || y <0) return 0;
	if (x == 0 && y == 0) return 1;
	ll &ret = dp[x][y];
	if (ret != -1) return ret;
	ret = 0;
	ret += go(x - 1, y) + go(x, y - 1);
	ret %= mod;
	return ret;
}
 int main() {
	scanf("%d", &t);
	memset(dp, -1, sizeof(dp));
	while (t--) {
		scanf("%d", &n);
		if (n % 2 == 1) printf("0\n");
		else printf("%lld\n", go(n/2,n/2));
	}
	return 0;
}