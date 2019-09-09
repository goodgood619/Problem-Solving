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
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n,k;
int dp[205][205];
int color[205];
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= 200; i++) {
		for (int j = 1; j <= 200; j++) {
			if (i == j) continue;
			dp[i][j] = 1e9;
		}
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &color[i]);
	}

	for (int k = 1; k <= n - 1; k++) {
		for (int i = 1; i <= n - k; i++) {
			int j = i + k;
			if (i == j) continue;
			int temp = 0;
			for (int p = i; p < j; p++) {
				temp = dp[i][p] + dp[p + 1][j];
				if (color[i] != color[p + 1]) temp += 1;
				dp[i][j] = min(dp[i][j], temp);
			}
		}
	}
	printf("%d\n", dp[1][n]);
	return 0;

}