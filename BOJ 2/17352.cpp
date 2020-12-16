#include<cstdio>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
int find(int u, vector<int>& parent) {
	if (parent[u] == u) return u;
	return parent[u] = find(parent[u], parent);
}
void uni(int u, int v, vector<int>& parent) {
	u = find(u, parent);
	v = find(v, parent);
	if (u == v) return;
	parent[u] = v;
}
int main() {
	int n;
	scanf("%d", &n);
	vector<int> parent;
	parent.assign(n + 1, 0);
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 0; i < n-2; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		if (find(first, parent) != find(second, parent)) {
			uni(first, second, parent);
		}
	}
	map<int, int> cnt;
	for (int i = 1; i <= n; i++) {
		find(i, parent);
	}
	map<int, int> m;
	for (int i = 1; i <= n; i++) {
		m[parent[i]]++;
	}
	for (auto it = m.begin(); it != m.end(); it++) {
		printf("%d ", it->first);
	}

	return 0;
}