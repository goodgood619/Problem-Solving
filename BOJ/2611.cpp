#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <map>
#include <set>
#include <list>
#include <climits>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
int n,m,Max;
vector<vector<P>> a;
int route[1005];
bool visited[1005];
int dist[1005];
#define INF 1e8
priority_queue<P, vector<P>> pq;
void dijk(int here) {
	// dist[next]>dist[here]+nextcost
	dist[here] = 0;
	pq.push({ 0,here });
	while (!pq.empty()) {
		int here = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		for (int i = 0; i < a[here].size(); i++) {
			int next = a[here][i].first;
			int nextcost = a[here][i].second;
			if (dist[next] < dist[here] + nextcost) {

				dist[next] = dist[here] + nextcost;
				route[next] = here;
				if (next != 1) pq.push({ dist[next],next });
			}
		}
	}

}
int main(){
	scanf("%d", &n);
	scanf("%d", &m);
	a.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		int first, second, cost;
		scanf("%d%d%d", &first, &second, &cost);
		a[first].push_back({ second,cost });
	}
	dijk(1);
	printf("%d\n", dist[1]);
	int st = 1;
	vector<int> ans;
	ans.push_back(1);
	while(1){
		ans.push_back(route[st]);
		st = route[st];
		if (st == 1) break;
	}
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d ", ans[i]);
	}
	return 0;
}