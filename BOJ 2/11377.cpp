#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
vector<vector<int>> a;
int n, m, k,ok;
int path[2010];
int visit[2010];
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
	scanf("%d%d%d", &n, &m,&k);
	a.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		int work;
		scanf("%d", &work);
		for (int j = 1; j <= work; j++) {
			int num;
			scanf("%d", &num);
			a[i].push_back(num);
		}
	}
	memset(path, -1, sizeof(path));
	for (int i = 1; i <= n; i++){
		memset(visit, 0, sizeof(visit));
		ok += dfs(i);
	}

	for (int i = 1; i <= n && k>0;i++){
		memset(visit, 0, sizeof(visit));
		if (dfs(i) == 1) {
			ok +=1;
			k--;
		}
	}
	printf("%d\n", ok);
	return 0;
}