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
int t;
int board[105][105];
P a[105];
int main() {
	scanf("%d", &t);
	while (t--) {
		int n,sx,sy,ex,ey;
		memset(board, 0, sizeof(board));
		scanf("%d", &n);
		scanf("%d%d", &sx, &sy);
		a[1] = { sx,sy };
		for (int i = 2; i <= n+1; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			a[i] = { x,y };
		}
		scanf("%d%d", &ex, &ey);
		a[n + 2] = { ex,ey };

		for (int i = 1; i <= n+2; i ++) {
			for (int j = 1; j <= n+2; j++) {
				int dist = abs(a[i].first - a[j].first) + abs(a[i].second - a[j].second);
				if (dist <= 1000) board[i][j] = 1;
			}
		}
		for (int k = 1; k <= n + 2; k++) {
			for (int i = 1; i <= n + 2; i++) {
				for (int j = 1; j <= n + 2; j++) {
					if (board[i][k] && board[k][j]) board[i][j] = 1;
				}
			}
		}
		
		board[1][n + 2] == 1 ? printf("happy\n") : printf("sad\n");
	}
	
	return 0;
}