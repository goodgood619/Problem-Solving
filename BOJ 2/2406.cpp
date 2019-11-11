#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <iostream>
#include <queue>
#include <functional>
using namespace std;
struct pos {
	int here;
	int next;
	int dist;
};
struct pp {
	int here;
	int next;
};
struct cmp {
	bool operator()(pos a, pos b) {
		if (a.dist != b.dist) return a.dist > b.dist;
		if (a.here != b.here) return a.here > b.here;
		if (a.next != b.next) return a.next > b.next;
	}
};
int find(int u,int *parent) {
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u], parent);
}
void uni(int u,int v,int *parent) {
	u = find(u, parent);
	v = find(v, parent);
	if (u == v) return;
	parent[u] = v;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int *parent = new int[n + 1];
	for (int i = 0; i <= n; i++) parent[i] = i;
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		int here, next;
		scanf("%d%d", &here, &next);
		int heretop = find(here, parent), nexttop = find(next, parent);
		if (heretop != nexttop) {
			uni(here, next, parent);
			cnt++;
		}
	}
	priority_queue<pos, vector<pos>, cmp> pq;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int w;
			scanf("%d", &w);
			pq.push({ i,j,w });
		}
	}
	vector<pp> v;
	int ans = 0;
	while (!pq.empty()) {
		if (cnt == n - 2) break;
		int here = pq.top().here;
		int next = pq.top().next;
		int dist = pq.top().dist;
		pq.pop();
		if (here == 1 || next == 1) continue;
		int heretop = find(here, parent), nexttop = find(next, parent);
		if (heretop != nexttop) {
			uni(here, next, parent);
			ans += dist;
			v.push_back({ here,next });
			cnt++;
		}
	}
	printf("%d %d\n", ans, v.size());
	for (int i = 0; i < v.size(); i++) printf("%d %d\n",v[i].here,v[i].next);
    delete[] parent;
	return 0;
}