#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
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
int gox[4] = { -1,0,1,0 };
int goy[4] = { 0,1,0,-1 };
int m;
char board[3][55];
int dp[3][55];
int go(int x, int y) {
	if (x <= 0 || board[x][y] == '#' || x>=3) return 1e9;
	if (y == m) return 1;
	int &ret = dp[x][y];
	if (ret != -1) return ret;
	ret = 1e9;
	ret = min(ret, go(x - 1, y)+1);
	ret = min(ret, go(x, y + 1)+1);
	ret = min(ret, go(x + 1, y) + 1);
	return ret;
}
int main() {
	scanf("%d",&m);
	for (int i = 1; i <= 2; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &board[i][j]);
		}
	}
	if (m == 1) {
		int sum = 0;
		for (int i = 1; i <= 2; i++) {
			if (board[i][1] == '.') sum++;
		}
		if (sum == 2) {
			printf("1\n");
		}
		else printf("0\n");
		return 0;
	}
	memset(dp, -1, sizeof(dp));
	int Max = 1e9;
	for (int i = 1; i <= 2; i++) {
		memset(dp, -1, sizeof(dp));
		Max=min(Max,go(i, 1));
	}
	for (int i = 1; i <= 2; i++) {
		for (int j = 1; j <= m; j++) {
			if (board[i][j] == '#') Max++;
		}
	}
	printf("%d\n",m*2-Max);
 	return 0;
}