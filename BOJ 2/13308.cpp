#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <list>
#include <climits>
#include <string.h>
#include <deque>
#include <functional>
using namespace std;
typedef long long ll;
#define INF 1000000000
typedef pair<ll,ll> P;
typedef pair<ll, pair<ll,ll>> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
int n, m;
ll gas[2505];
ll dist[2505][2505]; // n번정점을 기름가격 m으로 갈수있는 최소 비용
vector<vector<P>> a;
ll dijk(int here) {
	for (int i = 1; i <= 2500; i++) {
		for (int j = 1; j <= 2500; j++) {
			dist[i][j] = 1e14;
		}
	}
	priority_queue<PP, vector<PP>, greater<PP>> pq;
	pq.push({ 0,{here,gas[here]}}); // 최소금액, 현재정점, 주유가능최저금액
	dist[here][gas[here]] = 0;
	while (!pq.empty()) {
		ll cost = pq.top().first;
		ll here = pq.top().second.first;
		ll mingas = pq.top().second.second;
		if (here == n) {
			return cost;
		}
		pq.pop();
		for (int i = 0; i < a[here].size(); i++) {
			ll next = a[here][i].first;
			ll nextcost = a[here][i].second;
			if (dist[next][min(mingas, gas[next])]>cost+mingas*nextcost) {
				dist[next][min(mingas, gas[next])] = cost + mingas * nextcost;
				pq.push({ nextcost*mingas + cost,{next,min(mingas,gas[next])}});
			}
		}
	}
}
int main() {
	// 최소 주유가격을 계속 가져가면서, dist배열을 갱신을시키자
	scanf("%d%d", &n,&m);
	a.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &gas[i]);
	}
	for (int i = 1; i <= m; i++) {
		ll first, second, cost;
		scanf("%lld%lld%lld", &first, &second, &cost);
		a[first].push_back({ second,cost });
		a[second].push_back({ first,cost });
	}
	ll ans=dijk(1);
	printf("%lld\n", ans);
	return 0;
}