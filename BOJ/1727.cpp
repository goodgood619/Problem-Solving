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
typedef pair<pair<int, int>, pair<int, char>> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
using namespace std;
int n, m;
int dp[1001][1001];
int a[1001];
int b[1001];
int go(int n,int m) {
	if (m <= 0) return 0;
	if (n <= 0) return 1e9;
	int &ret = dp[n][m];
	if (ret != -1) return ret;
	ret = 1e9;
	ret = min(ret, min(go(n - 1, m), go(n - 1, m - 1) + abs(a[n] - b[m])));
	return ret;
}
int go2(int n, int m) {
	if (n <= 0) return 0;
	if (m <= 0) return 1e9;
	int &ret = dp[n][m];
	if (ret != -1) return ret;
	ret = 1e9;
	ret = min(ret, min(go2(n, m-1), go2(n - 1, m - 1) + abs(a[n] - b[m])));
	return ret;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
	sort(a + 1, a + n + 1);
	sort(b + 1, b + m + 1);
	memset(dp, -1, sizeof(dp));
	if(n>=m) printf("%d\n", go(n, m));
	else printf("%d\n", go2(n,m));
	return 0;
}