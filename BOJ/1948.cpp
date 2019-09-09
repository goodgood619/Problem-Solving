#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
typedef pair <int, int> P;
vector<vector<P>> a;
vector<vector<P>> b;
queue <int> q;
int n, m,start,en,cnt;
int indegree[100003];
int backdegree[100003];
int dp[100003];
bool visited[100003];
void bfs(){
	int vertex = q.front();
	while (!q.empty()) {
		int vertex = q.front();
		q.pop();
		for (int i = 0; i < a[vertex].size(); i++) {
			int nextvertex = a[vertex][i].first;
			int nextcost = a[vertex][i].second;
			indegree[nextvertex]--;
			dp[nextvertex] = max(dp[nextvertex], dp[vertex] + nextcost);
			if (indegree[nextvertex] == 0){
				q.push(nextvertex);
			}
		}
	}
}
void dfs(int vertex){
	if (visited[vertex]) return;
	visited[vertex] = true;
	for (int i = 0; i < b[vertex].size(); i++) {
		int backvertex = b[vertex][i].first;
		int backcost = b[vertex][i].second;
		if (dp[vertex] - backcost == dp[backvertex]) {
			cnt++;
			dfs(backvertex);
		}
	}
}
int main(){
	scanf("%d", &n);
	scanf("%d", &m);
	a.resize(n + 1);
	b.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		int first, second, cost;
		scanf("%d%d%d", &first, &second, &cost);
		a[first].push_back({ second,cost });
		b[second].push_back({ first,cost });
		indegree[second]++;
		backdegree[first]++;
	}
	scanf("%d%d", &start, &en);
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}
	bfs();
	printf("%d\n", dp[en]);
	for (int i = 1; i <= n; i++) {
		if (backdegree[i] == 0) {
			q.push(i);
		}
	}
	dfs(en);
	printf("%d\n", cnt);
	return 0;
}