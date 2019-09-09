#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <functional>
using namespace std;
typedef pair <int, int> P;
priority_queue<P, vector<P>, greater<P>> pq;
vector<vector<P>> a;
int n, m,t;
typedef long long ll;
ll total;
bool visited[10006];
void Prim(int here) {
	pq.push({ 0,here });
	while (!pq.empty()) {
		int cost = pq.top().first;
		int vertex = pq.top().second;
		pq.pop();
		if (visited[vertex]) continue;
		visited[vertex] = true;
		total += cost;
		for (int i = 0; i < a[vertex].size(); i++) {
			int nextcost = a[vertex][i].second;
			int nextvertex = a[vertex][i].first;
			if (!visited[nextvertex]) {
				pq.push({ nextcost,nextvertex });
			}
		}
	}
}
int main(){
	scanf("%d", &t);
	while (t--){
		a.clear();
		total = 0;
		memset(visited, false, sizeof(visited));
		scanf("%d%d", &n,&m);
		a.resize(n + 1);
		for (int i = 1; i <= m; i++) {
			int first, second;
			scanf("%d%d", &first, &second);
			a[first].push_back({ second,1 });
			a[second].push_back({ first,1 });
		}
		Prim(1);
		printf("%lld\n", total);
	}
	return 0;
}