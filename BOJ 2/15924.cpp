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
#define mod 1000000009
typedef pair<int,int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[2] = { -1,0 };
int goy[2] = { 0,-1 };
int n, m;
ll dp[3001][3001];
char board[3001][3001];
ll go(int x, int y) {
	ll &ret = dp[x][y];
	if (ret != -1) return ret;
	ret = 1;
	for (int i = 0; i <2; i++) {
		int nx = x + gox[i];
		int ny = y + goy[i];
		if (nx<1 || nx>n || ny<1 || ny>m) continue;
		if (i == 0 && board[nx][ny] == 'E' || i==1 && board[nx][ny]=='S') continue;
		ret += go(nx, ny);
		ret %= mod;
	}
	ret %= mod;
	return ret;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &board[i][j]);
		}
	}
	memset(dp, -1, sizeof(dp));
	printf("%lld\n", go(n, m) % mod);
	return 0;
}