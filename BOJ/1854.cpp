
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
#include <stack>
using namespace std;
typedef long long ll;
#define INF 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
vector<vector<P>> a;
vector<vector<int>> record;
int n, m,k;
priority_queue<int, vector<int>> dist[1005];
void dijk(int here) {
	priority_queue<P, vector<P>, greater<P>> pq;
	pq.push({ 0,here });
	dist[here].push(0);
	while (!pq.empty()) {
		int cost = pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (cost > dist[here].top()) continue;
		for (int i = 0; i < a[here].size(); i++) {
			int next = a[here][i].first;
			int nextcost = a[here][i].second;
			if (dist[next].size()<k) {
				dist[next].push(cost + nextcost);
				pq.push({ cost + nextcost,next });
			}
			else{
				if (dist[next].top()>cost+nextcost) { // 이게 왜 dist[i].top()
					dist[next].pop();
					dist[next].push(cost + nextcost);
					pq.push({cost+ nextcost,next });
				}
			}
		}
	}
}
int main() {
	scanf("%d%d%d", &n, &m,&k);
	a.resize(n + 1);
	record.resize(105);
	for (int i = 1; i <= m; i++) {
		int first, second, cost;
		scanf("%d%d%d", &first, &second, &cost);
		a[first].push_back({ second,cost });
	}
	dijk(1);

	for (int i = 1; i <= n; i++) {
		if (dist[i].size() < k) printf("-1\n");
		else {
			printf("%d\n", dist[i].top());
		}
	}

	return 0;
}