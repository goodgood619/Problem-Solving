#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
using namespace std;
int t,n,m;
typedef pair <int, int> P;
map<int, int> ans;
vector<vector<int>> a;
bool visited[1005];
void bfs(int here, int color) {
	queue <P> q;
	ans.insert({ here,color });
	q.push({ here,color });
	visited[here] = true;
	while (!q.empty()) {
		int here = q.front().first;
		int color = q.front().second;
		q.pop();
		for (int i = 0; i < a[here].size(); i++) {
			int next = a[here][i];
			if (!visited[next]) {
				visited[next] = true;
				q.push({ next,3 - color });
				ans.insert({ next,3-color});
			}
		}
	}
}
int main(){
	scanf("%d", &t);
	while (t--){
		a.clear();
		ans.clear();
		memset(visited, false, sizeof(visited));
		scanf("%d%d", &n, &m);
		a.resize(n + 1);
		for (int i = 1; i <= m; i++) {
			int first, second;
			scanf("%d%d", &first, &second);
			a[first].push_back(second);
			a[second].push_back(first);
		}
		if (n != 0){
			for (int i = 1; i <= n; i++){
				if (!visited[i]) {
					bfs(i, 1);
				}
			}
		}
		bool check = false;
		bool no = false;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < a[i].size(); j++) {
				int next = a[i][j];
				int nextcolor = ans[next];
				int herecolor = ans[i];
				if (herecolor == nextcolor) {
					check = true;
					break;
				}

			}
			if (check) break;
		}
		if (n == 0) no = true;
		if (no) printf("impossible\n");
		else {
			if (check) printf("impossible\n");
			else printf("possible\n");
		}
	}
	return 0;
}