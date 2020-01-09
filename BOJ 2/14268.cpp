#include <iostream>
#include <vector>
using namespace std;

int n, m, lazy[400001], tree[400001], l[100001], r[100001];
vector<vector<int>> p;

void dfs(int now, int &o) {
	l[now] = ++o;
	for (int next : p[now]) {
		dfs(next, o);
	}
	r[now] = o;
}

void update_lazy(int node, int s, int e) {
	if (lazy[node]) {
		tree[node] += (e - s + 1)*lazy[node];
		if (s != e) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}
void update(int node, int s, int e, int i, int j, int v) {
	update_lazy(node, s, e);
	if (j < s || e < i) return;
	if (i <= s && e <= j) {
		tree[node] += (e - s + 1)*v;
		if (s != e) {
			lazy[node * 2] += v;
			lazy[node * 2 + 1] += v;
		}
		return;
	}
	int m = (s + e) / 2;
	update(node * 2, s, m, i, j, v);
	update(node * 2 + 1, m + 1, e, i, j, v);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
int query(int node, int s, int e, int idx) {
	update_lazy(node, s, e);
	if (idx < s || e < idx) return 0;
	if (s == e) return tree[node];
	int m = (s + e) / 2;
	return query(node * 2, s, m, idx) + query(node * 2 + 1, m + 1, e, idx);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	p.resize(n + 1);
	int x;
	cin >> x;
	for (int i = 2; i < n + 1; i++) {
		cin >> x;
		p[x].push_back(i);
	}
	int o = 0;
	dfs(1, o);
	int c, y; 
	for (int i = 0; i < m; i++) {
		cin >> c;
		if (c == 1) {
			cin >> x >> y;
			update(1, 1, n, l[x], r[x], y);
		}
		else if (c == 2) {
			cin >> x;
			cout << query(1, 1, n, l[x]) << '\n';
		}
	}
}