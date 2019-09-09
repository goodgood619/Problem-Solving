#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>
#include <cstring>
using namespace std;
typedef pair <int, int> P;
priority_queue<P, vector<P>, greater<P>> pq;
vector<vector<P>> a;
#define inf (int) 1<<30
int n, m, start,en;
vector <int> dist(1001, inf);
void dijk(int start) {
	dist[start] = 0;
	pq.push({ 0,start });
	while (!pq.empty()) {
		int cost = pq.top().first;
		int vertex = pq.top().second;
		pq.pop();
		if (dist[vertex] < cost) continue;
		for (int i = 0; i < a[vertex].size(); i++){
			int newvertex = a[vertex][i].first;
			int newcost = a[vertex][i].second;
			if (dist[newvertex] > dist[vertex] + newcost) {
				dist[newvertex] = dist[vertex] + newcost;
				pq.push({ dist[vertex]+newcost,newvertex });
			}

		}
	}
}
int main() {
	scanf("%d", &n);
	scanf("%d", &m);
	a.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		int u, v, cost;
		scanf("%d%d%d", &u, &v, &cost);
		a[u].push_back({v,cost});
	}
	scanf("%d%d", &start, &en);
	dijk(start);
	printf("%d\n", dist[en]);
	return 0;
}
