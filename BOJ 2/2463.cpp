#include <cstdio>
#include <algorithm>
#include <cstdint>
#include <queue>
using namespace std;
typedef int64_t ll;
typedef pair<int, pair<int, int>> P;
int find(int u, int*& parent) {
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u], parent);
}
void uni(int u, int v, int*& parent, int*& size) {
	u = find(u, parent),v=find(v,parent);
	if (u == v) return;
	parent[u] = v;
	size[v] += size[u];
	size[u] = 1;
}
int main() {
	int n,m;
	scanf("%d%d", &n,&m);
	priority_queue<P, vector<P>> pq;
	int* parent = new int[n + 1];
	int* Size = new int[n + 1];
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		Size[i] = 1;
	}
	ll total = 0, ans = 0;
	for (int i = 0; i < m; i++) {
		int here, next, cost;
		scanf("%d%d%d", &here, &next, &cost);
		pq.push({ cost,{here,next} });
		total += cost;
	}
	ll mod = 1e9;
	while (!pq.empty()) {
		int cost = pq.top().first;
		int here = pq.top().second.first;
		int next = pq.top().second.second;
		pq.pop();
		int first = find(here, parent);
		int second = find(next, parent);
		if (first != second) {
			ans += (((total * Size[first]) % mod) * Size[second]) % mod;
			uni(here, next, parent, Size);
		}
		if (ans >= 1e9) ans %= mod;
		total -= cost;
	}
	printf("%lld\n", ans);
	delete[] parent, Size;
	return 0;
}