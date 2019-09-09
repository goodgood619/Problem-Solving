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
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, Case = 1,r,g,b;
int dp[101][101][101];
int go(int a,int b,int c) {
	if (a == 0 && b == 0 && c == 0) return 0;
	int &ret = dp[a][b][c];
	if (ret != -1) return ret;
	ret = 1e9;
	for (int i = 1; i <= 3; i++) {
		if (a >= i) ret = min(ret, go(a - i, b, c) + 1);
		if (b >= i) ret = min(ret, go(a, b - i, c) + 1);
		if (c >= i) ret = min(ret, go(a, b, c - i) + 1);
 	}
	if (a >= 1 && b >= 1) ret = min(ret, go(a - 1, b - 1, c) + 1);
	if (b >= 1 && c >= 1) ret = min(ret, go(a, b - 1, c - 1) + 1);
	if (a >= 1 && c >= 1) ret = min(ret, go(a - 1, b, c - 1) + 1);
	if (a >= 1 && b >= 1 && c >= 1) ret = min(ret, go(a - 1, b - 1, c - 1) + 1);
	return ret;
}
int main() {
	setbuf(stdout, NULL);
	scanf("%d%d%d", &r, &g, &b);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", go(r, g, b));
	return 0;
}