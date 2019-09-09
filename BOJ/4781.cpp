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
typedef pair < int,int > P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n;
double p;
vector<P> coin;
int dp[10005];
int go(int cost) {
	if (cost<=0) return 0;
	int &ret = dp[cost];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < coin.size(); i++) {
		if (cost - coin[i].second >= 0) {
			ret = max(ret, go(cost - coin[i].second) + coin[i].first);
		}
	}
	return ret;
}
int main() {
	while (1) {
		scanf("%d%lf", &n, &p);
		if (n == 0 && p == 0) break;
		coin.clear();
		for (int i = 1; i <= n; i++) {
			int m;
			double d;
			scanf("%d%lf", &m, &d);
			coin.push_back({ m,(int)(d*100+0.5)});
		}
		memset(dp, -1, sizeof(dp));
		printf("%d\n",go((int)(p*100+0.5)));
		
	}
	return 0;
}