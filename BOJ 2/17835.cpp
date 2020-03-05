#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
typedef int64_t ll;
struct p {
	int next, cost;
	p(int next, int cost) {
		this->next = next;
		this->cost = cost;
	}
};
ll dist[100001];
void dijk(priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq,vector<vector<p>> &graph) {
	while (!pq.empty()) {
		int here = pq.top().second;
		ll cost = pq.top().first;
		pq.pop();
		if (cost > dist[here]) continue;
		for (int i = 0; i < graph[here].size(); i++) {
			int next = graph[here][i].next;
			ll nextcost = graph[here][i].cost;
			if (dist[next] > dist[here] + nextcost) {
				dist[next] = dist[here] + nextcost;
				pq.push({ dist[next], next });
			}
		}
	}
}
int main() {
	int n,m,k;
	scanf("%d%d%d", &n, &m, &k);
	vector<vector<p>> graph;
	graph.assign(n + 1, vector<p>());
	for (int i = 1; i <= n; i++) dist[i] = 1e18;
	for (int i = 0; i < m; i++) {
		int here, next, cost;
		scanf("%d%d%d", &here, &next, &cost);
		graph[next].push_back(p(here, cost));
	}

	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	for (int i = 0; i < k; i++) {
		int start;
		scanf("%d", &start);
		dist[start] = 0;
		pq.push({ 0, start });
	}
	dijk(pq, graph);
	ll max = 0, idx = 0;
	for(int i=1;i<=n;i++) {
		if (max < dist[i] && dist[i] != 1e18) {
			max = dist[i];
			idx = i;
		}
 	}
	printf("%d\n%lld\n", idx, max);
	return 0;
}