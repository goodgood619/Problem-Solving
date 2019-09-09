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
using namespace std;
typedef long long ll;
#define INF 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n, m;
int par[40005][17];
int dist[40005];
int d[40005];
bool visited[40005];
vector<vector<P>> a;
void dfs(int here, int parent, int depth,int cost) {
	visited[here] = true;
	par[here][0] = parent;
	d[here] = depth;
	dist[here] = cost;
	for (int i = 0; i < a[here].size(); i++) {
		int next = a[here][i].first;
		int nextcost = a[here][i].second;
		if (!visited[next]) {
			dfs(next, here, depth + 1,cost+nextcost);
		}
	}
}
void make() {
	for (int j = 1; j <= 16; j++) {
		for (int i = 1; i <= n; i++) {
			par[i][j] = par[par[i][j - 1]][j - 1];
		}
	}
}
int lca(int a, int b) {
	if (d[a] > d[b]) swap(a, b);
	for (int i = 16; i >= 0; i--) {
		if (d[b] - d[a] >= (1 << i)) {
			b = par[b][i];
		}
	}
	if (a == b) return a;
	for (int i = 16; i >= 0; i--) {
		if (par[a][i] != par[b][i]) {
			a = par[a][i];
			b = par[b][i];
		}
	}
	return par[a][0];
}
int main() {
	scanf("%d", &n);
	a.resize(n + 1);
	for (int i = 1; i < n; i++) {
		int first, second, cost;
		scanf("%d%d%d", &first, &second, &cost);
		a[first].push_back({ second,cost });
		a[second].push_back({ first,cost });
	}
	dfs(1, 0, 0,0);
	make();
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		int l=lca(first, second);
		printf("%d\n", dist[first] + dist[second] - 2 * dist[l]);
	}
	return 0;
}