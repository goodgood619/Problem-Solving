#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <math.h>
using namespace std;
int n, m, s, v;
typedef pair<double, double> P;
P mouse[105];
P bunker[105];
int path[105];
bool visited[105];
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
	scanf("%d%d%d%d", &n, &m, &s, &v);
	a.resize(105);
	for (int i = 1; i <= n; i++) { scanf("%lf%lf", &mouse[i].first, &mouse[i].second);}
	for (int i = 1; i <= m; i++) { scanf("%lf%lf", &bunker[i].first, &bunker[i].second);}
	sort(mouse + 1, mouse + n + 1);
	sort(bunker + 1, bunker + m + 1);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			bool check = false;
			double x = mouse[i].first;
			double y = mouse[i].second;
			double bx = bunker[j].first;
			double by = bunker[j].second;
			double diff =sqrt((x - bx)*(x - bx) + (y - by)*(y - by));
			if (diff<=(double)s*v) {
				a[i].push_back(j);
			}
		}
	}
	memset(path, -1, sizeof(path));
	int ok = 0;
	for (int i = 1; i < a.size(); i++) {
		if (a[i].size() == 0) continue;
		memset(visited, false, sizeof(visited));
		ok += dfs(i);
	}
	printf("%d\n", n - ok);
	return 0;
}