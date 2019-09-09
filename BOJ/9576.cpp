#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
int visit[1005];
int path[1005];
int n, m,ans,t;
vector<vector<int>> a;
int dfs(int here){
	if (visit[here]) return 0;
	visit[here] = 1;
	for (int i = 0; i < a[here].size(); i++) {
		int next = a[here][i];
		if (path[next] == -1) {
			path[next] = here;
			return 1;
		}
		else if (dfs(path[next])){
			path[next] = here;
			return 1;
		}
	}
	return 0;
}
int main(){
	scanf("%d", &t);
	while (t--) {
		ans = 0;
		scanf("%d%d", &n, &m);
		a.clear();
		a.resize(m+1);
		for (int i = 1; i <= m; i++) {
			int first, second;
			scanf("%d%d", &first, &second);
			for (int j = first; j <= second; j++) {
				a[i].push_back(j);
			}
		}
		memset(path, -1, sizeof(path));
		for (int i = 1; i <= m; i++) {
			memset(visit, 0, sizeof(visit));
			int ok = dfs(i);
			if (ok == 1) ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}