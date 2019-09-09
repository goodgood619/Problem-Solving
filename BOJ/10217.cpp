#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <functional>
#include <vector>
using namespace std;
int t,n,m,k;
typedef pair<int, int> P;
typedef pair<int, pair <int, int>> PP;
vector<vector<PP>> a;
priority_queue<PP, vector<PP>, greater<PP>> pq;
int dist[105][10005];
#define INF 987654321
void dijk(int start){
	dist[start][m]= 0;
	pq.push({ 0,{start,m}});
	while (!pq.empty()) {
		int resttime= pq.top().first;
		int vertex = pq.top().second.first;
		int rest = pq.top().second.second;
		pq.pop();
		if (dist[vertex][rest] < resttime) continue;
		for (int i = 0; i < a[vertex].size(); i++) {
			int nextcost = a[vertex][i].first;
			int next = a[vertex][i].second.first;
			int nexttime = a[vertex][i].second.second;
			if (nextcost<=rest){
				int temp = rest - nextcost;
				if (dist[next][temp] > dist[vertex][rest] + nexttime) {
					dist[next][temp] = dist[vertex][rest] + nexttime;
					pq.push({dist[next][temp],{next,temp}});
				}
			}
		}
	}
}
int main(){
	scanf("%d", &t);
	while (t--){
		scanf("%d%d%d", &n, &m, &k);
		a.clear();
		a.resize(n + 1);
		memset(dist, 0, sizeof(dist));
		for (int i = 1; i <= k; i++){
			int first, second, co, ti;
			scanf("%d%d%d%d", &first, &second, &co, &ti);
			a[first].push_back({ co,{second,ti} });
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= m; j++){
			dist[i][j] = INF;
			}
		}
		if (k != 0) {
			dijk(1);
			int Min = INF;
			for (int i = 0; i <= m; i++) {
				if (dist[n][i] == INF) continue;
				else Min = min(Min, dist[n][i]);
			}
			if (Min == INF) printf("Poor KCM\n");
			else printf("%d\n", Min);
		}
		else if (k == 0) printf("Poor KCM\n");
	}
	return 0;
}