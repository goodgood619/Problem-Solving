#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int bfs(int x, int y, int &n, int &k, map<P, int> &dist, map<P, int> &visited) {
	if (k > 47) { //47번까지만
		int ans = -1e9;
		queue<PP> q;
		q.push({ {x,y},0 });
		while (!q.empty()) {
			int x = q.front().first.first;
			int y = q.front().first.second;
			int d = q.front().second;
			if (d == 47) ans = max(ans, x);
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + gox[i], ny = y + goy[i];
				if (visited.count({ nx,ny }) != 0) continue;
				else if (d + 1 <= 47) {
					visited[{nx, ny}]++;
					q.push({ {nx,ny},d + 1 });
				}
			}
		}
		ans += (k - 47);
		return ans;
	}
	else { //k번까지만
		int ans = -1e9;
		queue<PP> q;
		q.push({ {x,y},0 });
		while (!q.empty()) {
			int x = q.front().first.first;
			int y = q.front().first.second;
			int d = q.front().second;
			if (d == k) ans = max(ans, x);
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + gox[i], ny = y + goy[i];
				if (visited.count({ nx,ny }) != 0) continue;
				else if (d + 1 <= k) {
					visited[{nx, ny}]++;
					q.push({ {nx,ny},d + 1 });
				}
			}
		}
		return ans;
	}
}
int main()
{
	int n, k;
	scanf(" %d%d", &n, &k);
	map<P, int> visited, dist;
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		visited[{a, b}]++;
	}
	if (n == 0) {
		printf("%d\n", k);
		return 0;
	}
	int ans = bfs(0, 0, n, k, dist, visited);
	ans == -1e9 ? printf("0\n") : printf("%d\n", ans);
	return 0;
}