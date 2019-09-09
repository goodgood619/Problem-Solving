#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
queue <int> q;
int n, k;
bool visited[100010];
int cnt[100010];
void bfs(int index) {
	visited[index] = true;
	q.push(index);
	if (index != 0) {
		for (int i = index; i <= 100000; i *= 2) {
			visited[i] = true;
			q.push(i);
		}
	}
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		if (here == k) break;
		int x = here - 1;
		int y = here + 1;
		int z = here * 2;
		if (z != 0) {
			for (int i = z; i <= 100000; i *= 2) {
				if (!visited[i]) {
					visited[i] = true;
					q.push(i);
					cnt[i] = cnt[here];
				}
			}
		}
		if (x >= 0 && x <= 100000 && !visited[x]) {
			visited[x] = true;
			q.push(x);
			cnt[x] = cnt[here] + 1;
		}
		if (y >= 0 && y <= 100000 && !visited[y]) {
			visited[y] = true;
			q.push(y);
			cnt[y] = cnt[here] + 1;
		}
	}
}
int main() {
	scanf("%d%d", &n, &k);
	bfs(n);
	printf("%d\n", cnt[k]);
	return 0;
}
