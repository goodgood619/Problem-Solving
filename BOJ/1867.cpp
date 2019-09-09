#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
bool visited[505];
int path[505];
int n, m;
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
	scanf("%d%d", &n, &m);
	a.resize(n + 1);
		for (int j = 1; j <= m; j++) {
			int first, second;
			scanf("%d%d", &first, &second);
			a[first].push_back(second);
	}
	memset(path, -1, sizeof(path));
	int ok = 0;
	for (int i = 1; i <= n; i++){
		if (a[i].size() == 0) continue;
		memset(visited, false, sizeof(visited));
		ok += dfs(i);
	}
	printf("%d\n", ok);
	return 0;
}