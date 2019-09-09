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
typedef pair<pair<double, double>, pair<double, double>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int dp[505][505];
P checkpoint[505];
int n, k;
int dist(int here, int next) {
	return abs(checkpoint[here].first - checkpoint[next].first) + abs(checkpoint[here].second - checkpoint[next].second);
}
int go(int here, int jump) {
	if (here >=n) return 0;
	int &ret = dp[here][jump];
	if (ret != -1) return ret;
	ret = 1e9;
	for (int i = 0; i <= jump; i++) { //checkpoint를 0개부터 jump개까지 연속적으로 뛰어넘을수 있다(이게 겁나중요)
		if (here + i + 1 > n) continue;
		ret = min(ret, go(here + i + 1, jump - i) + dist(here, here + i + 1));
	}
	return ret;
}
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <=n; i++) {
		scanf("%d%d", &checkpoint[i].first, &checkpoint[i].second);
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", go(1, k));
	return 0;
}