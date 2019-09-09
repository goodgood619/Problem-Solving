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
typedef pair<int,int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n;
ll dp[2005][2005];
ll arr[2005];
ll dist(int here, int next) {
	return abs(arr[next] - arr[here]);
}
ll dist2(int x, int y) {
	ll sum = 0;
	for (int i = x; i < y; i++) {
		sum += abs(arr[i + 1] - arr[i]);
	}
	return sum;
}
ll go(int first, int second) {
	if (first == n || second == n) {
		return 0;
	}
	ll &ret = dp[first][second];
	if (ret != -1) return ret;
	ret = 1e12;
	int next = max(first, second) + 1;
	ret = min(ret, go(next, second) + dist(first, next));
	ret = min(ret, go(first, next) + dist(second, next));
	return ret;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &arr[i]);
	}
	if (n == 1) {
		printf("0\n");
		return 0;
	}
	memset(dp, -1, sizeof(dp));
	ll ans = 1e12;
	for (int i = 2; i <= n; i++) {
		ans=min(ans,go(i-1,i)+dist2(1,i-1));
	}
	printf("%lld\n", ans);
	return 0;
}