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
#define mod 10007
typedef pair<int, ll> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int dp[1005][12];
int n;
int go(int index, int num) {
	if (index >=n) return 1;
	int &ret = dp[index][num];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = num; i < 10; i++) {
		ret += go(index + 1, i);
		ret %= mod;
	}
	return ret;
}
int main() {
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	int ans = 0;
	for (int i = 0; i < 10; i++) {
		ans += go(1, i);
		ans %= mod;
	}
	printf("%d\n", ans);
	return 0;
}