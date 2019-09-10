#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
typedef long long ll;
vector<vector<int>> a;
bool visited[500005];
int n;
ll total;
void dfs(int here, int depth){
	int cnt = 0;
	visited[here] = true;
	for (int i = 0; i < a[here].size(); i++) {
		int next = a[here][i];
		if (!visited[next]){
			dfs(next, depth + 1);
			cnt++;
		}
	}
	if(cnt==0) total += depth;
}
int main(){
	scanf("%d", &n);
	a.resize(n + 1);
	for (int i = 1; i <= n-1; i++){
		int first, second;
		scanf("%d%d", &first, &second);
		a[first].push_back(second);
		a[second].push_back(first);
	}
	dfs(1, 0);
	if (total % 2 == 1) printf("Yes\n");
	else printf("No\n");
	return 0;
}