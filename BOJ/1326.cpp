#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <deque>
#include <functional>
using namespace std;
int n,st,en;
vector<vector<int>> a;
int jump[10001];
bool visited[10001];
int bfs(int st, int en) {
	queue<pair<int, int>> q;
	q.push({ st,0 });
	visited[st] = true;
	while (!q.empty()) {
		int here = q.front().first;
		int cnt = q.front().second;
		if (here == en) return cnt;
		q.pop();
		int temp = jump[here];
		for (int i = temp; here+i <= n; i += temp) {
			int next = here + i;
			if (!visited[next]) {
				visited[next] = true;
				q.push({ next,cnt + 1 });
			}
		}
		for (int i = temp; here-i >= 1; i += temp) {
			int next = here - i;
			if (!visited[next]) {
				visited[next] = true;
				q.push({ next,cnt + 1 });
			}
		}
	}
	return -1;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &jump[i]);
	scanf("%d%d", &st, &en);
	printf("%d\n",bfs(st, en));
	return 0;
}