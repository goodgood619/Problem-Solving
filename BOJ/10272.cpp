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
typedef pair<int,int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t,n;
P arr[515];
double dp[515][515];
double dist(int here, int next) {
	double x1 = arr[here].first, y1 = arr[here].second, x2 = arr[next].first, y2 = arr[next].second;
	return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}
double go(int x, int y) {
	if (x == n || y == n) {
		if (x != n) return dist(x, n);
		if (y != n) return dist(y, n);
		return 0;
	}
	double &ret = dp[x][y];
	if (ret != -1) return ret;
	ret = 1e10;
	int next = max(x, y) + 1;
	ret = min(ret, go(next, y) + dist(x, next));
	ret = min(ret, go(x, next) + dist(y, next));
	return ret;
}
int main() {
	scanf("%d", &t);
	while (t--) {
		memset(arr, 0, sizeof(arr));
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			arr[i] = { x,y };
		}
		for (int i = 0; i <= 514; i++) {
			for (int j = 0; j <= 514; j++) {
				dp[i][j] = -1;
			}
		}
		printf("%.2lf\n", go(1, 1));
	}
	return 0;
}