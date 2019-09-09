#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
vector<vector<int>> a;
bool visited[20005];
int n, m;
int color[20005];
// 1은 빨강 2는 파랑
void dfs(int here, int c){
	visited[here] = true;
	color[here] = c;
	for (int i = 0; i < a[here].size(); i++) {
		int next = a[here][i];
		if (!visited[next]) {
			dfs(next, 3 - c);
		}
	}
}
int main(){
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		a.clear();
		a.resize(n + 1);
		memset(visited, false, sizeof(visited));
		memset(color, 0, sizeof(visited));
		for (int i = 1; i <= m; i++) {
			int first, second;
			scanf("%d%d", &first, &second);
			a[first].push_back(second);
			a[second].push_back(first);
		}
		for (int i = 1; i <= n; i++) 
		{
			if(!visited[i] && color[i]==0) dfs(i, 1);
		}

		bool check = false;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < a[i].size(); j++) {
				int next = a[i][j];
				if (color[i] == color[next]){
					check = true;
					break;
				}

			}
			if (check) break;
		}
		if (check) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}