#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <functional>
#include <map>
#include <iostream>
#include <string>
using namespace std;
int n, m;
bool visited[1005];
int path[1005];
vector<vector<int>> a;
int dfs(int here) {
	if (visited[here]) return 0;
	visited[here] = true;
	for (int i = 0; i < a[here].size(); i++) {
		int next = a[here][i];
		if (path[next] == -1 || dfs(path[next])) {
			path[next] = here;
			return 1;
		}
	}
	return 0;
}
int main(){
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		a.clear();
		a.resize(n + 1);
		for (int i = 1; i <= m; i++) {
			int first, second;
			scanf("%d%d", &first, &second);
			a[first].push_back(second);
		}
		int ans = 0;
		memset(visited, false, sizeof(visited));
		memset(path, -1, sizeof(path));
		for (int i = 0; i < n; i++) {
			memset(visited, false, sizeof(visited));
			if (dfs(i)) ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}