#include <cstdio>
#include <algorithm>
#include <functional>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
int t;
typedef pair <int, int> P;
vector<vector<P>> a;
bool visited[10005];
vector<int> dist;
priority_queue<P, vector<P>, greater<P>> pq;
#define INF 987654321
int dijk(int st) {
	dist[st] = 0;
	pq.push({ 0,st });
	int cnt = 1;
	visited[st] = true;
	while (!pq.empty()) {
		int cost = pq.top().first;
		int vertex = pq.top().second;
		pq.pop();
		if (dist[vertex] < cost) continue;
		for (int i = 0; i < a[vertex].size(); i++) {
			int nextvertex = a[vertex][i].first;
			int nextcost = a[vertex][i].second;
			if (dist[nextvertex] > dist[vertex] + nextcost){
				dist[nextvertex] = dist[vertex] + nextcost;
				pq.push({dist[vertex] + nextcost, nextvertex});
				if (!visited[nextvertex]) {
					visited[nextvertex] = true;
					cnt++;
				}
			}
		}
	}
	return cnt;
}
int main(){
	scanf("%d", &t);
	while (t--) {
		int n, d, c;
		a.clear();
		dist.clear();
		memset(visited, false, sizeof(visited));
		scanf("%d%d%d",&n, &d, &c);
		a.resize(n + 1);
		dist.resize(n + 1);
		for (int i = 1; i <= d; i++) {
			int first, second, cost;
			scanf("%d%d%d", &first, &second, &cost);
			a[second].push_back({ first,cost });
		}
		dist.resize(n + 1);
		for (int i = 1; i <= n; i++) { dist[i] = INF; }
		int gam=dijk(c);
		int Max = 0;
		for (int i = 1; i <= n; i++) {
			if (dist[i] == INF) continue;
			else Max = max(Max, dist[i]);
		}
		printf("%d %d\n", gam, Max);
	}
	return 0;
}