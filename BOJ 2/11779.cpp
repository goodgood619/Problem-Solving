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
int n, m, start, en,k;
vector <int> dist(20001, inf);
vector <int> spot(10000, 0);
vector <int> realspot;
void dijk(int start){
	int st = start;
	dist[start] = 0;
	pq.push({ 0,start });
	while (!pq.empty()) {
		int cost = pq.top().first;
		int vertex = pq.top().second;
		pq.pop();
		if (dist[vertex] < cost) continue;
		for (int i = 0; i < a[vertex].size(); i++) {
			int newvertex = a[vertex][i].first;
			int newcost = a[vertex][i].second;
			if (dist[newvertex] > dist[vertex] + newcost) {
				dist[newvertex] = dist[vertex] + newcost;
				pq.push({ dist[vertex] + newcost,newvertex });
				spot[newvertex] = vertex;
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	a.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		int u, v, cost;
		scanf("%d%d%d", &u, &v, &cost);
		a[u].push_back({ v,cost });
	}
	scanf("%d%d", &start, &en);
	dijk(start);
	int p = en;
	while (p) {
		realspot.push_back(p);
		p = spot[p];
	}
	printf("%d\n", dist[en]);
	printf("%d\n", realspot.size());
	for (int i = realspot.size()-1; i >= 0; i--) {
		printf("%d ", realspot[i]);
	}
	return 0;
}