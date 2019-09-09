#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <cstring>
using namespace std;
int n, m;
typedef pair <int, int> P;
priority_queue<P, vector<P>, greater<P>> pq;
vector<vector<P>> a;
vector<int> dist;
vector<int> path;
#define INF 98765432
void dijk(int start) {
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
			if (dist[nextvertex] > dist[vertex] +nextcost){
				dist[nextvertex] = dist[vertex] + nextcost;
				pq.push({ dist[nextvertex],nextvertex });
				path[nextvertex] = vertex;
			}
		}
	}
}
int main(){
	scanf("%d%d", &n, &m);
	a.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		int first, second, cost;
		scanf("%d%d%d", &first, &second, &cost);
		a[first].push_back({ second,cost });
		a[second].push_back({ first,cost });
	}
	for (int i = 1; i <= n; i++){
		path.clear();
		path.resize(n + 1);
		dist.clear();
		dist.resize(n + 1);
		for (int i = 1; i <= n; i++) {
			dist[i] = INF;
		}
		dijk(i);
		for (int j = 1; j <= n; j++){
			if (i == j) printf("- ");
			else {
				bool check = false;
				int p = path[j];
				int idx = 0;
				while (p!= i) {
					idx = p;
					p = path[p];
					check = true;
				}
				if(check) printf("%d ", idx);
				else printf("%d ", j);
			}
		}
		printf("\n");
	}
	return 0;
}