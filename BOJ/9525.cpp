#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
vector<vector<int>> a;
int n, m, k,ok;
bool visited[105][105];
int row[105][105];
int col[105][105];
int path[6010];
int visit[6010];
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
	scanf("%d", &n);
	a.resize(6001);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char c;
			scanf(" %c", &c);
			if (c == 'X') {
				visited[i][j] = true;
			}
		}
	}
	int rcnt = 1;
	int ccnt = 1;
	for (int i = 1; i <= n; i++){
		bool okcheck = false;
		for (int j = 1; j <= n; j++) {
			if (visited[i][j]) {
				if (okcheck) {
					rcnt++;
					okcheck = false;
				}
				continue;
			}
			else {
				row[i][j] = rcnt;
				okcheck = true;
			}
		}
		if(okcheck)
		rcnt++;
	}
	for (int j = 1; j <= n; j++) {
		bool okcheck = false;
		for (int i= 1; i <= n; i++) {
			if (visited[i][j]) {
				if (okcheck) {
					ccnt++;
					okcheck = false;
				}
				continue;
			}
			else {
				col[i][j] = ccnt;
				okcheck = true;
			}
		}
		if (okcheck)
			ccnt++;
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++) {
			if (visited[i][j]) continue;
			else {
				a[row[i][j]].push_back(col[i][j]);
			}
		}
	}

	memset(path, -1, sizeof(path));
	for (int i = 1; i <=6000; i++) {
		if (a[i].size() == 0) continue;
		memset(visit, 0, sizeof(visit));
		ok+=dfs(i);
	}
	printf("%d\n", ok);
	return 0;
}