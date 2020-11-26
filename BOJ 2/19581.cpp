#include<cstring>
#include<string>
#include<algorithm>
#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<map>
using namespace std;
typedef long long ll;
struct p {
	int next, cost;
};
int Max, temp;
vector<int> ans;
void dfs(int here, int cost,vector<vector<p>> &graph, vector<bool> &visited) {
	visited[here] = true;
	if (Max < cost) {
		Max = cost;
		temp = here;
	}
	for (int i = 0; i < graph[here].size(); i++) {
		int next = graph[here][i].next;
		int nextcost = graph[here][i].cost;
		if (!visited[next]) {
			dfs(next, cost + nextcost,graph,visited);
		}
	}
	visited[here] = false;
}
void dfs2(int here, int cost, vector<vector<p>>& graph, vector<bool>& visited,int novisit) {
	visited[here] = true;
	if (Max >= cost) {
		ans.push_back(cost);
	}
	for (int i = 0; i < graph[here].size(); i++) {
		int next = graph[here][i].next;
		int nextcost = graph[here][i].cost;
		if (!visited[next] && novisit!=next) {
			dfs2(next, cost + nextcost, graph, visited,novisit);
		}
	}
	visited[here] = false;
}
int main() {
	int n;
	scanf("%d", &n);
	vector<vector<p>> graph;
	graph.assign(n + 1, vector<p>());
	vector<bool> visited;

	visited.assign(n + 1, false);
	for (int i = 1; i < n; i++) {
		int here, next, cost;
		scanf("%d%d%d", &here, &next, &cost);
		graph[here].push_back({ next,cost });
		graph[next].push_back({ here,cost });
	}
	dfs(1, 0,graph,visited);
	Max = 0;
	int b = temp;
	dfs(b, 0,graph,visited);
	int c = temp;
	dfs2(b, 0, graph, visited,c);
	dfs2(c, 0, graph, visited, b);
	sort(ans.begin(), ans.end());
	printf("%d\n", ans[ans.size() - 1]);
	return 0;
}