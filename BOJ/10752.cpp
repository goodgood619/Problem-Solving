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
int t, Case = 1,r,c,ans;
char board[16][16];
void dfs(int x,int y) {
	if (x == r && y == c) {
		ans++;
		return;
	}

	for (int i = x + 1; i <= r; i++) {
		for (int j = y + 1; j <= c; j++) {
			if (board[x][y] != board[i][j]) dfs(i, j);
		}
	}
}
int main() {
	setbuf(stdout, NULL);
	scanf("%d%d", &r, &c);
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			scanf(" %c", &board[i][j]);
		}
	}
	dfs(1, 1);
	printf("%d\n", ans);
	return 0;
}