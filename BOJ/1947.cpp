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
typedef pair<int, ll> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n;
ll dp[1000005];
int main() {
	dp[1] = 0, dp[2] = 1, dp[3] = 2;
	for (int i = 4; i <= 1000000; i++) {
		dp[i] = (i - 1)*dp[i - 1] + (i - 1)*dp[i - 2];
		dp[i] %= INF;
	}
	scanf("%d", &n);
	printf("%lld\n", dp[n] % INF);
	return 0;
}