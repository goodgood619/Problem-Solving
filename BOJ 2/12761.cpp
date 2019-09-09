#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
queue <int> q;
int a, b, n, m;
int dist[100001];
bool visited[100001];
int gox[2] = { 1,-1 };
int num[2];
void bfs(int x) {
	visited[x] = true;
	q.push(x);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < 2; i++) {
			int nx = x + gox[i];
			if (nx < 0 || nx>100000 || visited[nx]) continue;
			if (!visited[nx]) {
				visited[nx] = true;
				q.push(nx);
				dist[nx] = dist[x] + 1;
			}
		}
		for (int i = 0; i < 2; i++) {
			int nx = x + num[i];
			if (nx < 0 || nx>100000 || visited[nx]) continue;
			if (!visited[nx]) {
				visited[nx] = true;
				q.push(nx);
				dist[nx] = dist[x] + 1;
			}
		}
		for (int i = 0; i < 2; i++) {
			int nx = x-num[i];
			if (nx < 0 || nx>100000 || visited[nx]) continue;
			if (!visited[nx]) {
				visited[nx] = true;
				q.push(nx);
				dist[nx] = dist[x] + 1;
			}
		}
		for (int i = 0; i < 2; i++) {
			int nx = x*num[i];
			if (nx < 0 || nx>100000 || visited[nx]) continue;
			if (!visited[nx]) {
				visited[nx] = true;
				q.push(nx);
				dist[nx] = dist[x] + 1;
			}
		}
		for (int i = 0; i < 2; i++) {
			int nx = x*-(num[i]);
			if (nx < 0 || nx>100000 || visited[nx]) continue;
			if (!visited[nx]) {
				visited[nx] = true;
				q.push(nx);
				dist[nx] = dist[x] + 1;
			}
		}
	}
	return;
}
int main(){
	scanf("%d%d%d%d", &num[0], &num[1], &n, &m);
	bfs(n);
	printf("%d\n", dist[m]);
	return 0;
}