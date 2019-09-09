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
int n,m;
int board[1005][1005];
int dp[1005][1005];
int main() {
	scanf("%d%d", &n,&m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %1d", &board[i][j]);
		}
	}

	for (int i = 1; i <= n; i++) {
		if(board[i][1]==1) dp[i][1] = 1;
	}

	for (int i = 1; i <= m; i++) {
		if (board[1][i] == 1) dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= m; j++) {
			if (board[i][j] == 0) continue;
			else {
				board[i][j] = min(board[i - 1][j],min(board[i - 1][j - 1],board[i][j - 1]))+1;
			}
		}
	}

	int Max = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			Max = max(Max, board[i][j]);
		}
	}
	printf("%d\n", Max*Max);
	return 0;

}