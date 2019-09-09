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
int t, Case = 1, n, m;
vector<vector<pair<int,int>>> a,b;
vector<int> acost, bcost;
bool visited[18];
void dfs(int here,int cost,int flag) {
	if (here == n) {
		if (flag) bcost.push_back(cost);
		else acost.push_back(cost);
		return;
	}
	visited[here] = true;
	if (!flag) {
		for (int i = 0; i < a[here].size(); i++) {
			int next = a[here][i].first;
			int nextcost = a[here][i].second;
			if (!visited[next]) {
				dfs(next, cost + nextcost, flag);
			}
		}
	}
	else {
		for (int i = 0; i < b[here].size(); i++) {
			int next = b[here][i].first;
			int nextcost = b[here][i].second;
			if (!visited[next]) {
				dfs(next, cost + nextcost, flag);
			}
		}
	}
	visited[here] = false;
}
int main() {
	setbuf(stdout, NULL);
	scanf("%d%d", &n, &m);
	a.resize(n + 1);
	b.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		int first, second, cost1, cost2;
		scanf("%d%d%d%d", &first, &second, &cost1, &cost2);
		a[first].push_back({ second,cost1 });
		b[first].push_back({ second,cost2 });
	}
	dfs(1,0, 0);
	memset(visited, false, sizeof(visited));
	dfs(1,0,1);
	sort(acost.begin(), acost.end());
	sort(bcost.begin(), bcost.end());
	for (int i = 0; i < acost.size(); i++) {
		vector<int>::iterator it = lower_bound(bcost.begin(), bcost.end(), acost[i]);
		if (*it == acost[i]) {
			printf("%d\n", *it);
			return 0;
		}
	}
	printf("IMPOSSIBLE\n");
	return 0;
}
