#include <cstdio>
#include <algorithm>
#include <cstdint>
#include <vector>
typedef int32_t Int;
typedef int64_t ll;
using namespace std;
struct p {
	int depth, cur;
};
void dfs(int here,int parent,int depth,vector<vector<Int>> &graph,bool* &visited,int** &par, int* &d) {
	visited[here] = true;
	d[here] = depth;
	par[here][0] = parent;
	for (int i = 0; i < graph[here].size(); i++) {
		int next = graph[here][i];
		if (!visited[next]) {
			dfs(next, here, depth + 1, graph, visited, par, d);
		}
	}
}
void make(int n,int** &par) {
	for (int j = 1; j <= 17; j++) {
		for (int i = 1; i <= n; i++) {
			par[i][j] = par[par[i][j - 1]][j - 1];
		}
	}
}
int lca(int a,int b,int* &d,int** &par) {
	if (d[a] > d[b]) swap(a, b);
	for (int i = 17; i >= 0; i--) {
		if (d[b] - d[a] >= (1 << i)) {
			b = par[b][i];
		}
	}
	if (a == b) return a;
	for (int i = 17; i >= 0; i--) {
		if (par[a][i] != par[b][i]) {
			a = par[a][i];
			b = par[b][i];
		}
	}
	return par[a][0];
}
bool compare(const p& a, const p& b) {
	return a.depth > b.depth;
}
int main() {
	Int n,m;
	scanf("%d", &n);
	vector<vector<Int>> graph;
	graph.assign(n + 1, vector<Int>());
	bool* visited = new bool[n + 1];
	Int** par = new int* [n + 1];
	for (int i = 0; i <= n; i++) par[i] = new int[18];
	Int* d = new int[n + 1];
	for (int i = 0; i <= n; i++) {
		d[i] = 0;
		visited[i] = false;
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= 17; j++) {
			par[i][j] = 0;
		}
	}
	for (int i = 0; i < n - 1; i++) {
		Int here, next;
		scanf("%d%d", &here, &next);
		graph[here].push_back(next);
		graph[next].push_back(here);
	}

	dfs(1, 0, 0,graph,visited,par,d);
	make(n, par);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		vector<p> ans;
		int r, u, v;
		scanf("%d%d%d", &r, &u, &v);
		int lca1 = lca(r,u,d,par);
		int lca2 = lca(r,v,d,par);
		int lca3 = lca(u,v,d,par);
		ans.push_back({ d[lca1],lca1 });
		ans.push_back({ d[lca2],lca2 });
		ans.push_back({ d[lca3],lca3 });
		sort(ans.begin(), ans.end(), compare);
		printf("%d\n", ans[0].cur);
	}
	for (int i = 0; i <= n; i++) delete[] par[i];
	delete[] d, visited,par;
	graph.clear();
	return 0;
}