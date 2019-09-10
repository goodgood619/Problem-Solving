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
int gox[4] = { 0,1,-1,0};
int goy[4] = { 1,0,0,-1};
int n, m;
int board[35][35];
ll dp[35][35][35][35][3];
ll go(int sx, int sy, int ex, int ey,int flag) {
	if (ex == n && ey == n) {
		return 1;
	}
	ll &ret = dp[sx][sy][ex][ey][flag];
	if (ret != -1) return ret;
	ret = 0;
	if (flag == 0) { // 가로모양
		if (ex <= n && ey + 1 <= n && board[ex][ey+1]!=1) ret += go(ex, ey, ex, ey + 1, flag);
		if (ex + 1 <= n && ey + 1 <= n && board[ex + 1][ey + 1] != 1 && board[ex][ey + 1] != 1 && board[ex + 1][ey] != 1) ret += go(ex, ey, ex + 1, ey + 1, 2);
	}
	else if (flag == 1) { //세로모양
		if (ex + 1 <= n && ey <= n && board[ex + 1][ey] != 1) ret += go(ex, ey, ex + 1, ey, flag);
		if (ex + 1 <= n && ey + 1 <= n && board[ex + 1][ey + 1] != 1 && board[ex][ey + 1] != 1 && board[ex + 1][ey] != 1) ret += go(ex, ey, ex + 1, ey + 1, 2);
	}
	else { //대각선
		if (ex <= n && ey + 1 <= n && board[ex][ey + 1] != 1) ret += go(ex, ey, ex, ey + 1, 0);
		if (ex + 1 <= n && ey <= n && board[ex + 1][ey] != 1) ret += go(ex, ey, ex + 1, ey, 1);
		if (ex + 1 <= n && ey + 1 <= n && board[ex + 1][ey + 1] != 1 && board[ex][ey + 1] != 1 && board[ex + 1][ey] != 1) ret += go(ex, ey, ex + 1, ey + 1, 2);
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
	printf("%lld\n", go(1, 1,1,2,0));
	return 0;
}