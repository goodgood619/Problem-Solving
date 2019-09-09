#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int n, k, p;
bool visited[105];
bool check;
int blue[105];
int white[105];
vector<vector<int>> a;
// false: 청, true:흰
void dfs(int here, bool check) {
	if (visited[here]) return;
	if (!check) blue[k++] = here;
	else white[p++] = here;
	visited[here] = true;
	for (int i = 0; i < a[here].size(); i++) {
		int next = a[here][i];
		if (!visited[next]) {
			dfs(next, !check);
		}
	}
}
int main() {
	scanf("%d", &n);
	a.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		int cnt;
		scanf("%d", &cnt);
		for (int j = 1; j <= cnt; j++) {
			int who;
			scanf("%d", &who);
			a[i].push_back(who);
		}
	}

	for (int i = 1; i <= n; i++) {
		check = false;
		if (!visited[i]) {
			dfs(i, check);
		}
	}
	sort(blue, blue + k);
	sort(white, white + p);
	printf("%d\n", k);
	for (int i = 0; i < k; i++) {
		printf("%d ", blue[i]);
	}
	printf("\n");
	printf("%d\n", p);
	for (int i = 0; i < p; i++) {
		printf("%d ", white[i]);
	}
	return 0;
}