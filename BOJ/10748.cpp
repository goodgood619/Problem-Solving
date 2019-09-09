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
int board[105][105];
ll dp[105][105];
int n, m, k;
ll go(int x, int y,int num) {
	if (x == n && y == m) return 1;
	if (x == n && y != m) return 0;
	if (y == m && x != n) return 0;
	ll &ret = dp[x][y];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = x + 1; i <= n; i++) {
		for (int j = y + 1; j <= m; j++) {
			if (board[i][j] != num) {
				ret += go(i, j, board[i][j]);
				ret %= mod;
			}
		}
	}
	return ret%mod;
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %d", &board[i][j]);
		}
	}
	memset(dp, -1, sizeof(dp));
	printf("%lld\n", go(1, 1,board[1][1]) % mod);
	return 0;
}