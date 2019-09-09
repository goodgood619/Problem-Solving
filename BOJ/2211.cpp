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
#define mod 1000000007
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { -1,0,0,1 };
int goy[4] = { 0,1,-1,0 };
int n,m;
vector<vector<P>> a;
vector<P> ans;
void dijk(int st) {
	int dist[1005] = { 0, };
	for (int i = 1; i <= n; i++) dist[i] = 1e9;
	dist[st] = 0;
	priority_queue<PPP, vector<PPP>, greater<PPP>> pq;
	pq.push({ 0,{st,-1}});
	while (!pq.empty()) {
		int cost = pq.top().first;
		int here = pq.top().second.first;
		int pre = pq.top().second.second;
		pq.pop();
		if (cost > dist[here]) continue;
		if (pre != -1) ans.push_back({ here,pre });
		for (int i = 0; i < a[here].size(); i++) {
			int next = a[here][i].first;
			int nextcost = a[here][i].second;
			if (dist[next] > dist[here] + nextcost) {
				dist[next] = dist[here] + nextcost;
				pq.push({ dist[next],{next,here} });
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	a.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		int left, right, cost;
		scanf("%d%d%d", &left, &right, &cost);
		a[left].push_back({ right,cost });
		a[right].push_back({ left,cost });
	}
	dijk(1);
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}
	return 0;
}