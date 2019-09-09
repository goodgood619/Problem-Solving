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
int board[501][501];
int dp[501][501];
int n;
int go(int x,int y) {
	if (x > n || y > n) return 0;
	int &ret = dp[x][y];
	if (ret != -1) return ret;
	ret = 0;
	ret = max(ret, max(go(x + 1, y) + board[x][y], go(x + 1, y + 1) + board[x][y]));
	return ret;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			scanf(" %d", &board[i][j]);
		}
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", go(1, 1));
	return 0;
}