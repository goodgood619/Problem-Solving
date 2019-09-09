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
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int dp[2005][2005];
int a[2005], b[2005];
int n;
int go(int left, int right) {
	if (left >= n || right >= n) return 0;
	int &ret = dp[left][right];
	if (ret != -1) return ret;
	ret = 0;
	if (a[left+1] > b[right+1]) {
		ret = max(ret, go(left, right + 1) + b[right + 1]);
		ret = max(ret, go(left + 1, right + 1));
	}
	else {
		ret = max(ret, go(left + 1, right));
		ret = max(ret, go(left + 1, right + 1));
	}
	return ret;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", go(0, 0));
	return 0;
}