#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <math.h>
using namespace std;
typedef pair<int,pair<int, int>> P;
vector<vector<int>> a;
int n, m, k,ok,p;
P shark[60];
bool check[60][60];
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
	scanf("%d", &n);
	a.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		int p, q, r;
		scanf("%d%d%d", &p, &q, &r);
		shark[i].first = p;
		shark[i].second.first = q;
		shark[i].second.second = r;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			else {
					if (shark[i].first >= shark[j].first && shark[i].second.first >= shark[j].second.first && shark[i].second.second >= shark[j].second.second) {
						if (check[i][j] || check[j][i]) continue;
						a[i].push_back(j);
						check[i][j] = true;
						check[j][i] = true;
				}
			}
		}
	}
	memset(path, -1, sizeof(path));
	int p = n;
	for (int i = 1; i <= n; i++) {
		memset(visit, 0, sizeof(visit));
		if (dfs(i) == 1) {
			p--;
		}
	}
	for (int i = 1; i <= n; i++) {
		memset(visit, 0, sizeof(visit));
		if (dfs(i) == 1) {
			p--;
		}
	}
	printf("%d\n", p);
	return 0;
}