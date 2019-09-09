#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n, m,Max;
int make[101][101];
int dp[101][101];
bool visited[101];
vector<vector<int>> a;
int indegree[101];
queue <int> q;
void bfs() {
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		for (int i = 0; i < a[here].size(); i++) {
			int nhere = a[here][i];
			indegree[nhere]--;
			if (indegree[nhere] == 0) {
				q.push(nhere);
			}
			if (visited[here]){
				dp[nhere][here] += make[nhere][here];
			}
			else {
				for (int j = 0; j < make[nhere][here]; j++) {
					for (int k = 1; k <=Max; k++) {
						if (dp[here][k] == 0) continue;
						else dp[nhere][k] += dp[here][k];
					}
				}
			}
		}
	}
}
int main(){
	scanf("%d", &n);
	scanf("%d", &m);
	a.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		int v, u, k;
		scanf("%d%d%d", &v, &u, &k);
		indegree[v]++;
		a[u].push_back(v);
		make[v][u]=k;
	}
	for (int i = 1; i <= n; i++) {
		if (indegree[i]== 0){
			Max = max(Max, i);
			visited[i] = true;
			q.push(i);
		}
	}
	bfs();
	for (int i = 1; i <= n; i++) {
		if (visited[i]) {
			printf("%d %d\n", i, dp[n][i]);
		}
	}
	return 0;
}