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
typedef pair<char, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, Case = 1,n,m;
int dp[10001];
int go(int here) {
	if (here > n) return 0;
	if (here == n) return 1;
	int &ret = dp[here];
	if (ret != -1) return ret;
	ret = 0;
	ret += go(here + 1);
	ret %= mod;
	ret += go(here + m);
	ret %= mod;
	return ret;
}
int main() {
	setbuf(stdout, NULL);
	memset(dp, -1, sizeof(dp));
	scanf("%d%d", &n, &m);
	printf("%d\n", go(0) % mod);
	return 0;
}