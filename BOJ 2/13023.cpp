#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
vector<vector<int>> a;
int n, m;
bool visited[2005];
bool ok;
void dfs(int here,int sum){
	if (ok) return;
	if (sum >= 5) ok = true;
	if (visited[here]) return;
	visited[here] = true;
	for (int i = 0; i < a[here].size(); i++) {
		int next = a[here][i];
		if (!visited[next]) {
			dfs(next,sum+1);
		}
	}
	visited[here] = false;
}
int main(){
	scanf("%d%d", &n, &m);
	a.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		a[first].push_back(second);
		a[second].push_back(first);
	}
	for (int i = 1; i <= n; i++){
		if (!ok) dfs(i,1);
		if (ok) break;
	}
	if (ok) printf("1\n");
	else printf("0\n");
	return 0;
}