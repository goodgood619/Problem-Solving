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
typedef pair<pair<int, int>, pair<int,int>> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
using namespace std;
int dp[1005][1005];
int path[1005][1005];
int n, m;
P crime[1005];
int dist(int p, int next,int who) {
	if (who == 0) {
		if(p==0) return abs(crime[next].first -1) + abs(crime[next].second -1);
		return abs(crime[next].first - crime[p].first) + abs(crime[next].second - crime[p].second);
	}
	else {
		if (p == 0) return abs(crime[next].first - n) + abs(crime[next].second - n);
		return abs(crime[next].first - crime[p].first) + abs(crime[next].second -crime[p].second);
	}
}
int go(int p1, int p2) {
	if (p1 == m || p2 == m) return 0;
	int &ret = dp[p1][p2];
	if (ret != -1) return ret;
	int Max = max(p1, p2) + 1;
	int dist1 = go(Max , p2) + dist(p1, Max, 0);
	int dist2 = go(p1, Max) + dist(p2, Max, 1);

	if (dist1 > dist2) {
		ret = dist2;
		path[p1][p2] = 2;
	}
	else {
		ret = dist1;
		path[p1][p2] = 1;
	}
	return ret;
}
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		crime[i] = { x,y };
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n",go(0, 0));
	int left = 0, right = 0;
	vector<int> v;
	while (path[left][right] != 0) {
		v.push_back(path[left][right]);
		if (path[left][right] == 1) left=max(left,right)+1;
		else right=max(left,right)+1;
	}
	for (int i = 0; i < v.size(); i++) {
		printf("%d\n", v[i]);
	}
	return 0;
}