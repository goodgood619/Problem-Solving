#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <functional>
#include <vector>
using namespace std;
typedef pair <int, int> P;
vector<vector<P>> a;
priority_queue<P, vector<P>, greater<P>> pq;
int n,m,t,start,via1,via2;
int ans[2005];
vector<int> dist;
#define INF 98765432
int dijk(int start,int en){
	if (start == en) return 0;
	dist.clear();
	dist.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}
	dist[start] = 0;
	pq.push({ 0,start });
	while (!pq.empty()) {
		int cost = pq.top().first;
		int vertex = pq.top().second;
		pq.pop();
		if (dist[vertex] < cost) continue;
		for (int i = 0; i < a[vertex].size(); i++) {
			int nextvertex = a[vertex][i].first;
			int nextcost = a[vertex][i].second;
			if (dist[nextvertex] > dist[vertex] + nextcost) {
				dist[nextvertex] = dist[vertex] + nextcost;
				pq.push({ dist[nextvertex],nextvertex });
			}
		}
	}

	return dist[en];
}
int main(){
	int T;
	scanf("%d", &T);
	while (T--){
		int k = 0;
		memset(ans, 0, sizeof(ans));
		a.clear();
		scanf("%d%d%d", &n, &m, &t);
		scanf("%d%d%d", &start, &via1, &via2);
		a.resize(n + 1);
		for (int i = 1; i <= m; i++) {
			int first, second, cost;
			scanf("%d%d%d", &first, &second, &cost);
			a[first].push_back({ second,cost });
			a[second].push_back({ first,cost });
		}
		for (int i = 1; i <= t; i++){
			int en;
			scanf("%d", &en);
			int ok1 = dijk(start, via1) + dijk(via1, via2) + dijk(via2, en);
			int ok2 = dijk(start, via2) + dijk(via2, via1) + dijk(via1, en);
			int ok3 = dijk(start, en);
			if (ok1 == ok3 || ok2 == ok3) ans[k++] = en;
		}
		sort(ans, ans + k);
		for (int i = 0; i < k; i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
	return 0;
}