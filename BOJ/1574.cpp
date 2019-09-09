#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
vector<vector<int>> a;
int n, m, k,ok;
bool visited[305][305];
int row[305][305];
int col[305][305];
int path[1010];
int visit[1010];
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
	scanf("%d%d%d", &n, &m, &k);
	a.resize(1001);
	for (int i = 1; i <= k; i++){
		int first, second;
		scanf("%d%d", &first, &second);
		visited[first][second] = true;
	}
	int rcnt = 1;
	int ccnt = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			row[i][j] = rcnt;
		}
		rcnt++;
	}
	for (int j = 1; j <= m; j++) {
		for (int i = 1; i <= n; i++) {
			col[i][j] = ccnt;
		}
		ccnt++;
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++) {
			if (visited[i][j]) continue;
			else {
				a[row[i][j]].push_back(col[i][j]);
			}
		}
	}

	memset(path, -1, sizeof(path));
	for (int i = 1; i <=1000; i++) {
		if (a[i].size() == 0) continue;
		memset(visit, 0, sizeof(visit));
		ok+=dfs(i);
	}
	printf("%d\n", ok);
	return 0;
}