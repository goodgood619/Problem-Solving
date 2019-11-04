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
int go(int x,int y,int **board,int **dp,int cnt,int &n) {

	int& ret = dp[x][y];
	if (ret != -1) {
		return ret;
	}
	ret = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + gox[i], ny = y + goy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n || board[nx][ny] <= board[x][y]) continue;
		ret = max(ret,go(nx, ny, board, dp,cnt+1, n)+1);
	}
	return ret;
}
int main() {
	int n;
	scanf("%d", &n);
	int** board = new int* [n];
	int** dp = new int*[n];
	for (int i = 0; i < n; i++) {
		board[i] = new int[n];
		dp[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %d", &board[i][j]);
			dp[i][j] = -1;
		}
	}
	int ans = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans= max(ans,go(i, j, board, dp,1,n));
		}
	}
	printf("%d\n", ans);
	for (int i = 0; i < n; i++) {
		delete[] board[i];
		delete[] dp[i];
	}
	delete[] board;
	delete[] dp;
 	return 0;
}