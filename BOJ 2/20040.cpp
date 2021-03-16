#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<int, pair<int, int>> P;
int find(int u, vector<int>& parent) {
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u], parent);
}
void Union(int a, int b, vector<int>& parent) {
	a = find(a, parent);
	b = find(b, parent);
	if (a == b) return;
	parent[a] = b;
}
int main() {
	int n, m;
	scanf("%d%d", &n,&m);
	vector<int> graph,parent;
	graph.assign(n, 0);
	parent.assign(n, 0);
	int ans = 0;
	for (int i = 0; i < n; i++) parent[i] = i;
	for (int i = 0; i < m; i++) {
		int s1, s2;
		scanf("%d%d", &s1, &s2);
		int s1Root = find(s1, parent);
		int s2Root = find(s2, parent);
		if (s1Root == s2Root) {
			ans = i+1;
			break;
		}
		Union(s1, s2, parent);
	}
	printf("%d\n", ans);
	return 0;
}