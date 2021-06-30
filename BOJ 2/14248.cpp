#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
void bfs(int start, vector<int>& road) {
	int n = road.size();
	vector<bool> visited;
	visited.assign(n,false);
	visited[start] = true;
	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		int rightJump = here + road[here];
		int leftJump = here - road[here];
		if (rightJump < n && !visited[rightJump]) {
			visited[rightJump] = true;
			q.push(rightJump);
		}
		if (leftJump >= 0 && !visited[leftJump]) {
			visited[leftJump] = true;
			q.push(leftJump);
		}
	}

	int ans = 0;
	for (int i = 0; i < visited.size(); i++) {
		if (visited[i]) {
			ans++;
		}
	}

	printf("%d\n", ans);
}
int main() {
	int n,start;
	scanf("%d", &n);
	vector<int> road;
	road.assign(n,0);
	for (int i = 0; i < n; i++) {
		scanf(" %d", &road[i]);
	}
	scanf("%d", &start);
	start--;
	bfs(start, road);

	return 0;
}