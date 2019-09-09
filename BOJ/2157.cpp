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
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n, m, k;
int board[305][305];
int dp[305][305];
int go(int here, int j) {
	//if (j > m) return -1e9;
	if (here == n) return 0;
	int &ret = dp[here][j];
	if (ret != -1) return ret;
	ret = 0;
	bool check = false;
	for (int i = here + 1; i <= n; i++) {
		if (board[here][i] == -1) continue; //길없음
		if (j + 1 <= m) { // 하나이상 앞길이 존재하는 경우
			check = true;
			ret = max(ret, go(i, j + 1) + board[here][i]);
		}
	}
	if (!check) { // 앞으로 갈길이 아예없는경우
		ret = -1e9;
		return ret;
	}
	return ret;
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	memset(board, -1, sizeof(board));
	for (int i = 1; i <= k; i++) {
		int left, right, cost;
		scanf("%d%d%d", &left, &right, &cost);
		board[left][right] = max(board[left][right], cost);
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", go(1, 1));
	return 0;
}