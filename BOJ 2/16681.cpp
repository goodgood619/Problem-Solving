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
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
ll n, m, d, e;
ll height[100005];
vector<vector<pair<ll, ll>>> a;
//16681 등산(생각의전환-> 내리막길-> 오르막길로 바꿔야함)
//-> 다익스트라 시간복잡도(Elogv) ->우선순위큐
//-> V->100000 E->200000
//-> 200000*log100000-> mlogn이랑 비슷
//-> 1초안에 충분히 가능
//-> 다익스트라 
//-> 특정정점에서 모든정점까지의 최단거리
//-> 최단거리를 소모하는 체력이라고 가정
//-> 1번정점에서 모든 정점까지의 최단거리
//-> n번정점에서 모든 정점까지의 최단거리
//(이 말은 결국 오르막길이랑 똑같다는뜻임)
//(내리막길을 오르막길로 바꾸자!)
// 사이즈도 커서 예외처리 해줘야함 안하면 시간초과!!!
vector<ll> dijk(int here) {
	vector<ll> dist;
	dist.resize(n + 1);
	for (int i = 1; i <= n; i++) dist[i] = 1e14;
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
	dist[here] = 0;
	pq.push({ 0,here });
	while (!pq.empty()) {
		ll cost = pq.top().first;
		ll here = pq.top().second;
		pq.pop();
		if (dist[here] < cost) continue; // 사이즈가 커서 예외처리해줘야함
		for (int i = 0; i < a[here].size(); i++) {
			ll next = a[here][i].first;
			ll nextcost = a[here][i].second;
			if (height[next] <= height[here]) continue;
			if (dist[next] > dist[here] + nextcost) {
				dist[next] = dist[here] + nextcost;
				pq.push({ dist[next],next });
			}
		}
	}
	return dist;
}
int main() {
	scanf("%lld%lld%lld%lld", &n, &m, &d, &e);
	for (int i = 1; i <= n; i++) scanf("%lld", &height[i]);
	a.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		ll first, second, cost;
		scanf("%lld%lld%lld", &first, &second, &cost);
		a[first].push_back({ second,cost });
		a[second].push_back({ first,cost });
	}
	vector<ll> left, right;
	left.resize(n + 1);
	right.resize(n + 1);
	left = dijk(1);
	right = dijk(n);
	ll Max = -1e17;
	for (int i = 1; i <= n; i++) {
		if (left[i] == 1e14 || right[i] == 1e14) continue;
		else Max = max(Max, height[i] * e - (left[i] + right[i])*d);
	}
	if (Max == -1e17) printf("Impossible\n");
	else printf("%lld\n", Max);
	return 0;
}