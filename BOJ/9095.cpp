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
int n, t;
int dp[12];
int go(int n) {
	if (n ==1) return 1;
	if (n == 2) return 2;
	if (n == 3) return 4;
	int &ret = dp[n];
	if (ret != -1) return ret;
	ret = 0;
	ret = go(n - 1)+go(n-2)+go(n-3);
	return ret;
}
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		memset(dp, -1, sizeof(dp));
		printf("%d\n", go(n));
	}
	return 0;
}