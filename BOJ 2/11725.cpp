#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
int n;
vector<vector<int>> a;
int parent[100005];
bool visited[100005];
void dfs(int here,int pre) {
	visited[here] = true;
	parent[here] = pre;
	for (int i = 0; i < a[here].size(); i++) {
		int next = a[here][i];
		if (!visited[next]) {
			dfs(next, here);
		}
	}
	
}
int main() {
	scanf("%d", &n);
	a.resize(n + 1);
	for (int i = 1; i < n; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		a[first].push_back(second);
		a[second].push_back(first);
	}

	dfs(1, 0);
	for (int i = 2; i <= n; i++) {
		printf("%d\n", parent[i]);
	}
	return 0;
}