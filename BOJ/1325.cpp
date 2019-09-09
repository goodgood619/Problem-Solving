#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
vector<vector<int>> a;
bool visited[10004];
int ans[10004];
int n, m,Max;
queue <int> q;
int bfs(int here) {
	visited[here] = true;
	q.push(here);
	int cnt = 1;
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		for (int i = 0; i < a[here].size(); i++) {
			int next = a[here][i];
			if (!visited[next]){
				visited[next] = true;
				q.push(next);
				cnt++;
			}
		}
	}
	return cnt;
}
int main(){
	scanf("%d%d", &n, &m);
	a.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		a[second].push_back(first);

	}
	
	for (int i = 1; i <= n; i++){
		if (!visited[i]){
			int a=bfs(i);
			ans[i] = a;
			Max=max(a, Max);
		}

		memset(visited, false, sizeof(visited));
	}

	for (int i = 1; i <= n; i++) {
		if (Max == ans[i]) {
			printf("%d ", i);
		}
		else continue;
	}

	return 0;
}