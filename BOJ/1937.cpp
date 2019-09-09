
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
int gox[4] = { 1,0,0,-1};
int goy[4] = { 0,-1,1,0};
int n;
int board[505][505];
int dp[505][505];
int go(int x, int y) {
	int &ret = dp[x][y];
	if (ret != -1) return ret;
	ret = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + gox[i];
		int ny = y + goy[i];
		if (nx<1 || nx>n || ny<1 || ny>n) continue;
		if (board[x][y] < board[nx][ny]) {
			int temp=max(ret,go(nx, ny) + 1);
			ret = temp;
		}
	}
	return ret;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <=n; j++) {
			scanf(" %d", &board[i][j]);
		}
	}
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			go(i, j);
		}
	}
	int Max = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			Max = max(Max, dp[i][j]);
		}
	}
	printf("%d\n", Max);
	return 0;
}
