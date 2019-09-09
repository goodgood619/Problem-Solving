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
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, Case = 1,start,en,n,ans=1e9;
vector<vector<PPP>> a,b;
vector<int> path;
int main() {
	setbuf(stdout, NULL);
	scanf("%d%d%d", &start, &en, &n);
	vector<int> cost;
	vector<vector<int>> route;
	cost.resize(n + 1);
	route.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		int cities,st;
		scanf("%d%d", &cost[i], &cities);
		route[i].resize(cities + 1);
		for (int j = 0; j < cities; j++) {
			int num;
			scanf("%d", &num);
			route[i][j] = num;
		}
	}
	vector<int> au(10002, 1e9);
	vector<int> ub(10002, 1e9);
	au[start] = 0,ub[en]=0;
	for (int i = 1; i <= n; i++) {
		int C = cost[i];
		int idxa = route[i].size(), idxb = -1;
		for (int j = 0; j < route[i].size(); j++) {
			int here = route[i][j];
			if (here == start) {
				idxa = j;
			}
			else if (here == en) {
				idxb = j;
			}
		}

		for (int j = 0; j < route[i].size(); j++) {
			if (idxa <= j) {
				au[route[i][j]] = min(au[route[i][j]], C);
			}
			if (j <= idxb) {
				ub[route[i][j]] = min(ub[route[i][j]], C);
			}
		}

	}
	int ans = 1e9;
	for (int i = 1; i <= 10000; i++) {
		ans = min(ans, au[i] + ub[i]);
	}
	ans == 1e9 ? printf("-1\n") : printf("%d\n", ans);
	return 0;
}
