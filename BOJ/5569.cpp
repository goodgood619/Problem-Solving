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
int n, m;
int dp[105][105][2][2];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) dp[i][1][0][0] = 1;
	for (int i = 1; i <= m; i++) dp[1][i][1][0] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= m; j++) {
			dp[i][j][0][0] = (dp[i - 1][j][0][0] + dp[i - 1][j][0][1])%100000;
			dp[i][j][0][1] = dp[i - 1][j][1][0];
			dp[i][j][1][0] = (dp[i][j - 1][1][0] + dp[i][j - 1][1][1])%100000;
			dp[i][j][1][1] = dp[i][j - 1][0][0];
		}
	}
	printf("%d\n", (dp[n][m][0][0] + dp[n][m][0][1] + dp[n][m][1][0] + dp[n][m][1][1]) % 100000);
	return 0;

}