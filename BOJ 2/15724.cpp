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
int gox[4] = { 0,1,-1,0};
int goy[4] = { 1,0,0,-1};
vector<ll> v;
int n, m,k;
int board[1026][1026];
int dp[1026][1026];
int main() {
	scanf(" %d %d", &n,&m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %d", &board[i][j]);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + board[i][j];
		}
	}
	scanf(" %d", &k);
	for (int i = 1; i <= k; i++) {
		int a, b, c, d;
		scanf(" %d %d %d %d", &a, &b, &c, &d);
		printf("%d\n", dp[c][d] - dp[c][b-1] - dp[a-1][d] + dp[a-1][b-1]);
	}
	return 0;
}