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
int gox[4] = { 0,1,-1,0};
int goy[4] = { 1,0,0,-1};
int n, h, m;
int roof[305][15];
int ans = 1e9;
bool check() {
	for (int i = 1; i <= n; i++) {
		int cur = i;
		for (int j = 1; j <= m; j++) {
			if (roof[j][cur]) cur += 1;
			else if (cur - 1 > 0 && roof[j][cur - 1]) cur -= 1;
		}
		if (cur != i) return false;
	}
	return true;
}
void go(int x,int y,int cnt,int depth) {
	if (cnt == depth) {
		if (check()) {
			ans = min(ans, depth);
		}
		return;
	}
	for (int i = x; i <= m; i++) {
		for (int j = 1; j < n; j++) {
			if (roof[i][j]==0 && roof[i][j - 1] == 0 && roof[i][j + 1] == 0) {
				roof[i][j] = 1;
				go(i, j, cnt + 1, depth);
				roof[i][j] = 0;
			}
		}
	}
}
int main() {
	scanf("%d%d%d", &n, &h, &m);
	for (int i = 1; i <= h; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		roof[x][y] = 1;
	}

	for (int i = 0; i <= 3; i++) {
		go(1, 1, 0,i);
	}
	ans == 1e9 ? printf("-1\n") : printf("%d\n", ans);
	return 0;
}