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
int t, Case = 1, n, arr[2001];
int dp[2001][2001];
int go(int n1, int n2) {
	if (n1 == n || n2 == n) return 0;
	int &ret = dp[n1][n2];
	if (ret != -1) return ret;
	ret = 1e9;
	int Max = max(n1, n2) + 1;
	if (n1 == 0 && n2 != 0) ret = min(ret, min(go(Max, n2), go(n1, Max) + abs(arr[n2] - arr[Max])));
	if (n1 != 0 && n2 == 0) ret = min(ret, min(go(Max, n2) + abs(arr[n1] - arr[Max]), go(n1, Max)));
	ret = min(ret, min(go(Max, n2) + abs(arr[n1] - arr[Max]), go(n1, Max) + abs(arr[n2] - arr[Max])));
	return ret;
}
int main() {
	setbuf(stdout, NULL);
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	printf("%d\n", min(go(1, 0),go(0,1)));
	return 0;
}