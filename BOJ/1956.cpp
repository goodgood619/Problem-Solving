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
int gox[4] = { 1, 0,0,-1 };
int goy[4] = { 0, 1,-1,0 };
int n,m;
int board[405][405];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) board[i][j] = 1e9;
		}
	}
	for (int i = 1; i <= m; i++) {
		int left, right,cost;
		scanf("%d%d%d", &left, &right,&cost);
		board[left][right] = cost;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (board[i][j]>board[i][k] + board[k][j]) board[i][j] = board[i][k]+board[k][j];
			}
		}
	}
	
	int ans = 1e9;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) ans = min(ans, board[i][j] + board[j][i]);
		}
	}
	ans == 1e9 ? printf("-1\n") : printf("%d\n", ans);
	return 0;
}