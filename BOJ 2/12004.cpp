#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
int parent[200005];
int Size[200005];
int check[200005];
int arr[200005];
int ok[200005];
int n, m;
vector<vector<int>> a;
int find(int u) {
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}
void merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return;
	parent[u] = v;
	Size[v] += Size[u];
}
int main(){
	scanf("%d%d", &n, &m);
	a.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		a[first].push_back(second);
		a[second].push_back(first);
	}
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		Size[i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = n; i >= 1; i--) {
		int what = arr[i];
		check[what] = 1;
		for (int j = 0; j < a[what].size(); j++) {
			int next = a[what][j];
			if (check[next]) {
				merge(next,what);
			}
		}
		if (Size[what] == n - i + 1)
			ok[i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (ok[i]) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}