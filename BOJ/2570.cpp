#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
vector<vector<int>> a;
int n, m, k,ok;
bool visited[105][105];
int goleft[105][105];
int goright[105][105];
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
	scanf("%d", &m);
	a.resize(6001);
	for (int i = 1; i <= m; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		visited[first][second] = true;
	}
	int rcnt = 1;
	int ccnt = 1;
	for (int i = 1, j = 1; i <= n; j++) {
		bool okcheck = false;
		for (int k = i, p = j;k<=n&& p >= 1;k++,p--){
			if (visited[k][p]){
				if (okcheck) {
					rcnt++;
					okcheck = false;
				}
				continue;
			}
			else {
				goleft[k][p] = rcnt;
				okcheck = true;
			}
		}
		if (okcheck) rcnt++;
		if (j == n){
			j--;
			i++;
		}
	}

	for (int i = 1, j =n; i <= n; j--) {
		bool okcheck = false;
		for (int k = i, p = j; k <= n&& p<=n; k++, p++) {
			if (visited[k][p]) {
				if (okcheck) {
					ccnt++;
					okcheck = false;
				}
				continue;
			}
			else {
				goright[k][p] = ccnt;
				okcheck = true;
			}
		}
		if (okcheck) ccnt++;
		if (j == 1) {
			j++;
			i++;
		}
	}

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++) {
			if (visited[i][j]) continue;
			else {
				a[goleft[i][j]].push_back(goright[i][j]);
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
