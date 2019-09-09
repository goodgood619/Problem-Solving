
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
int dp[1005][1005];
int n, k;
int go(int n, int k) {
	if (n < 0 || k < 0) return 0;
	if (n == 0 || k == 0 || n==k) return 1;
	int &ret = dp[n][k];
	if (ret != -1) return ret;
	ret = 0;
	ret = go(n - 1, k - 1)%10007 + go(n - 1, k)%10007;
	return ret%10007;
}
int main() {
	scanf("%d%d", &n,&k);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", go(n, k) % 10007);
	return 0;
}