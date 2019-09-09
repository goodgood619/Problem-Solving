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
int board[105][105];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int left, right;
		scanf("%d%d", &left, &right);
		board[left][right] = 1;
		board[right][left] = 1;
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (board[i][k] && board[k][j]) board[i][j] = 1;
			}
		}
	}
	int ans = 0;
	for (int i = 2; i <= n; i++) {
		if (board[1][i]) ans++;
	}
	printf("%d\n", ans);
	return 0;
}