#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <math.h>
using namespace std;
vector<vector<int>> a;
int n, m,ok;
int path[2010];
int visit[2010];
bool visited[1005];
int dfs(int here) {
	if (visit[here]) return 0;
	visit[here] = 1;
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
		a.resize(102);
		int Max = 0;
		ok = 0;
		for (int i = 1; i <= m; i++) {
			int start,en,sid;
			scanf("%d%d%d", &start, &en,&sid);
			Max = max(Max, en);
			for (int j = 1; j <= sid; j++) {
				int num;
				scanf("%d", &num);
				for (int k = start; k <= en; k++) {
					a[k].push_back(num);
				}
			}
		}
		memset(path, -1, sizeof(path));
		bool check = false;
		int ti = 0;
		int ans = 0;
		for (int i = 0; i <Max; i++){
			if (a[i].size() == 0) continue;
			memset(visit, 0, sizeof(visit));
			if (dfs(i) == 1) {
				ti++;
				if (ti == n){
					ans = i;
					check = true;
					break;
				}
			}
		}
		if (!check) printf("-1\n");
		else printf("%d\n", ans+1);
	}
	return 0;
}