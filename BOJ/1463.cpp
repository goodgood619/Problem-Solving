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
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n;
int dp[1000001];
int go(int n) {
	if (n == 1) return 0;
	int &ret = dp[n];
	if (ret != -1) return ret;
	ret = 1e9;
	if (n % 3 == 0) ret = min(ret, go(n / 3)+1);
	if (n % 2 == 0) ret = min(ret, go(n / 2) + 1);
	if (n >= 2) ret = min(ret, go(n - 1) + 1);
	return ret;
}
int main() {
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", go(n));
	return 0;
}