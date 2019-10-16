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
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t,n;
int dp[13][1 << 13];
int dist[13][13];
int go(int index, int via) {
	if (via == (1 << n) - 3) {
		return dist[index][1];
	}
	int &ret = dp[index][via];
	if (ret != -1) return ret;
	ret = 1e9;
	for (int i = 0; i < n; i++) {
		if (i == 0 || i == 1) continue;
		if (!(via &(1 << i))) {
			ret = min(ret, go(i, via | (1 << i)) + dist[index][i]);
		}
	}
	return ret;
}
int main() {
	scanf("%d", &t);
	int Case = 1;
	while (t--) {
		scanf("%d", &n);
		n += 2;
		memset(dist, 0, sizeof(dist));
		int st = 0, en = 1;
		vector<P> v;
		for (int i = 0; i < n; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			v.push_back({ x,y });
		}
		for (int i = 0; i < v.size(); i++) {
			for (int j = i + 1; j < v.size(); j++) {
				dist[i][j] = abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second);
				dist[j][i] = dist[i][j];
			}
		}
		memset(dp, -1, sizeof(dp));
		printf("#%d %d\n", Case++, go(st, (1 << st)));
	}
	return 0;
}