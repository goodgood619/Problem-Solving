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
typedef pair<double, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { -1,0,1,0 };
int goy[4] = { 0,1,0,-1 };
int main() {
	int n;
	scanf("%d", &n);
	int *dp = new int[n + 1];
	dp[1] = 2;
	for (int i = 2; i <= n; i++) {
		if (i % 2 == 0) dp[i] = dp[i - 1];
		else dp[i] = 2 * dp[i - 1];
		dp[i] %= 16769023;
	}
	printf("%d\n", dp[n]);
	return 0;
}