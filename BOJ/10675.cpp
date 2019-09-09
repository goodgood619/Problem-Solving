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
int t, Case = 1,start,en,n;
vector<vector<pair<int, int>>> a;
int main() {
	setbuf(stdout, NULL);
	scanf("%d%d%d", &start, &en, &n);
	a.resize(10002);
	for (int i = 1; i <= n; i++) {
		int cost, cities,st;
		scanf("%d%d", &cost, &cities);
		vector<pair<int, int>> v;
		scanf("%d", &st);
		v.push_back({ st,cost });
		for (int j = 1; j < cities; j++) {
			int next;
			scanf("%d", &next);
			v.push_back({next,cost });
		}
		a.push_back(v);
	}
	int ans = 1e9;
	for (int i = 0; i < a.size(); i++) {
		int idx = -1;
		for (int j = 0; j < a[i].size(); j++) {
			if (a[i][j].first == start) {
				idx = j;
				break;
			}
		}
		if (idx == -1) continue;
		int c = 1e9;
		for (int j = idx + 1; j < a[i].size(); j++) {
			if (a[i][j].first == en) {
				c = a[i][j].second;
				break;
			}
		}
		if (c == 1e9) continue;
		ans = min(ans, c);
	}
	ans == 1e9 ? printf("-1") : printf("%d\n", ans);
	return 0;
}
