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
typedef pair<int, int> P;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = {0,1,-1,0};
int goy[4] = {1,0,0,-1};
int n,st;
double dist[16][16];
double dp[16][1<<16];
double go(int st,int here, int via) {
	if (via == (1 << n) - 1) {
		return dist[here][st];
	}
	double &ret = dp[here][via];
	if (ret != -1) return ret;
	ret = 1e9;
	for (int i = 0; i < n; i++) {
		int next = i;
		if (next == here) continue;
		if (!(via & (1 << next))) ret = min(ret, go(st,next, via | (1 << next))+dist[here][next]);
	}
	return ret;
}
int main(void) {
	scanf("%d", &n);
	vector<P> v;
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		v.push_back({ x,y });
	}
	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			int diffx = abs(v[i].first - v[j].first), diffy = abs(v[i].second - v[j].second);
			double d = sqrt(diffx * diffx + diffy * diffy);
			dist[i][j] = d;
			dist[j][i] = d;
		}
	}
	double ans = 1e10;
	for (int i = 0; i < n; i++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= (1 << n); j++) {
				dp[i][j] = -1;
			}
		}
		ans = min(ans, go(i,i, (1 << i)));
	}
	printf("%.6lf\n", ans);
	return 0;
}