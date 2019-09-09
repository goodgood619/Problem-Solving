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
typedef pair<pair<int, int>, pair<int, int>> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
using namespace std;
int n, k;
int dp[1001];
int arr[1001];
int go(int index) {
	if (index >= n) return 0;
	int &ret = dp[index];
	if (ret != -1) return ret;
	ret = 1e9;
	for (int i = index; i <= index + arr[index]; i++) {
		ret = min(ret, go(i) + 1);
	}
	return ret;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	memset(dp, -1, sizeof(dp));
	int ans = go(1);
	ans == 1e9 ? printf("-1\n") : printf("%d\n", ans);
	return 0;
}