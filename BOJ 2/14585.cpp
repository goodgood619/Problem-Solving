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
using namespace std;
typedef long long ll;
#define INF 1000000000
#define mod 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
ll dp[305][305];
int board[305][305];
int n, m;
ll go(int x, int y) {
	if (x > 300 || y > 300) return 0;
	ll &ret = dp[x][y];
	if (ret != -1) return ret;
	ret = 0;
	ret = max(go(x + 1, y), go(x, y + 1));
	if (board[x][y] - (x + y) > 0) {
		ret += board[x][y] - (x + y);
	}
	return ret;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		board[first][second] = m;
	}
	memset(dp, -1, sizeof(dp));
	printf("%lld\n", go(0, 0));
	return 0;

}
