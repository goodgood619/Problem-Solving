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
int dp[17][1<<17];
int n;
int board[17][17];
int go(int here, int via) {
	if (via == (1 << n) - 1) {
		if (board[here][0] == 0) return INF;
		else return board[here][0];
	}
	int &ret = dp[here][via];
	if (ret != -1) return ret;
	ret = 1e9;
 	for (int i = 0; i <n; i++) {
		int next = i;
		if (board[here][next] == 0) continue;
		if ( here!=next && !(via & (1 << i))) {
			ret=min(ret,go(next, via | (1 << i))+board[here][next]);
		}
	}
	return ret;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i <n; i++) {
		for (int j = 0; j <n; j++) {
			scanf(" %d", &board[i][j]);
		}
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n",go(0, 1));
	return 0;

}