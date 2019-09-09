#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
int n, m,cnt;
bool visited[10010];
vector <int> a[10010];
queue <int> q;
int visit[10010];
void bfs(int now) {
	q.push(now);
	visited[now] = true;
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		for (int i = 0; i<a[here].size(); i++) {
			int next = a[here][i];
			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
				visit[next] = visit[here] + 1;
			}
		}
	}
}
int main()
{
	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		a[u].push_back(v);
		a[v].push_back(u);
	}
	bfs(1);
	for (int i = 1; i <= n; i++) {
		if (visit[i] == 1 || visit[i] == 2)
			cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}