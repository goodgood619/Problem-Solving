#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
typedef long long ll;
using namespace std;
typedef pair < ll, pair < ll,ll>> PP;
typedef pair<ll, ll> P;
priority_queue<PP, vector<PP>, greater<PP>> pq;
vector<vector<P>> a;
int n, m, k;
ll dist[10005][25];
ll INF = 10000000000000;
void dijk(int start) {
	dist[start][k] = 0;
	pq.push({ 0,{start,k}});
	while (!pq.empty()) {
		ll cost = pq.top().first;
		ll vertex = pq.top().second.first;
		ll ok = pq.top().second.second;
		pq.pop();
		for (int i = 0; i < a[vertex].size(); i++){
			ll next = a[vertex][i].first;
			ll nextcost = a[vertex][i].second;
				if (dist[next][ok] > dist[vertex][ok] + nextcost) {
					dist[next][ok] = dist[vertex][ok] + nextcost;
					pq.push({ dist[next][ok],{next,ok}});
				}
			if(ok>0){
				ll good = ok - 1;
				if (dist[next][good] > dist[vertex][ok]) {
					dist[next][good] = dist[vertex][ok];
					pq.push({ dist[next][good],{next,good}});
				}
			}
		}
	}
}
int main(){
	scanf("%d%d%d", &n, &m, &k);
	a.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		ll first, second, cost;
		scanf("%lld%lld%lld", &first, &second, &cost);
		a[first].push_back({ second,cost });
		a[second].push_back({ first,cost });
	}
	for (int i = 1; i <= n; i++){
		for (int j = 0; j <= k; j++) {
			dist[i][j] = INF;
		}
	}
	dijk(1);
	ll Min = INF;
	for (int i = 0; i <= k; i++) {
		if (dist[n][i] == INF) continue;
		else Min = min(Min, dist[n][i]);
 	}
	printf("%lld\n", Min);
	return 0;
}