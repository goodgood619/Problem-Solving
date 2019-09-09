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
int gox[4] = { -1,1,1,-1 };
int goy[4] = { 1,1,-1,-1 };
int par[30005][17];
int depth[30005];
bool visited[30005];
int dp[16][1 << 16];
int n,m;
vector<vector<int>> a;
void dfs(int here, int parent, int cnt) {
	visited[here] = true;
	par[here][0] = parent;
	depth[here] = cnt;
	for (int i = 0; i < a[here].size(); i++) {
		int next = a[here][i];
		if (!visited[next]) {
			dfs(next, here, cnt + 1);
		}
	}
}
void make() {
	for (int j = 1; j < 17; j++) {
		for (int i = 1; i <= n; i++) {
			par[i][j] = par[par[i][j - 1]][j - 1];
		}
	}
}

int lca(int a, int b) {
	if (depth[a] > depth[b]) swap(a, b);
	for (int i = 16; i >= 0; i--) {
		if (depth[b] - depth[a] >= (1 << i)) {
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
		int left, right;
		scanf("%d%d", &left, &right);
		a[left].push_back(right);
		a[right].push_back(left);
	}
	dfs(1,-1,0);
	make();
	int st = 1;
	int sum = 0;
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		int next;
		scanf("%d", &next);
		sum+=depth[st] + depth[next] - 2*depth[lca(st,next)];
		st = next;
	}
	printf("%d\n", sum);
	return 0;
}