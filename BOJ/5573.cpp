
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
int board[1005][1005];
int dp[1005][1005];
int n, m, k;
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %d", &board[i][j]);
		}
	}

	dp[1][1] = k- 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (dp[i][j] == 0) continue;

			dp[i][j + 1] += dp[i][j] / 2;
			dp[i + 1][j] += dp[i][j] / 2;

			if (dp[i][j] % 2 == 1) {
				if (board[i][j] == 1) dp[i][j + 1]++;
				else dp[i + 1][j]++;
			}
			board[i][j] = (board[i][j] + dp[i][j]) % 2;
		}
	}

	int i = 1, j = 1;
	while (i <= n && j <= m) {
		if (board[i][j] == 1) j++;
		else i++;
	}
	printf("%d %d\n", i, j);
	return 0;
}