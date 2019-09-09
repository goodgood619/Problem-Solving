#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <math.h>
using namespace std;
typedef pair<pair<int, int>, int> P;
P board[3005];
bool visited[3005];
int n,t;
vector<vector<int>> a;
void dfs(int here) {
	if (visited[here]) return;
	visited[here] = true;
	for (int i = 0; i < a[here].size(); i++) {
		int next = a[here][i];
		if (!visited[next]) {
			dfs(next);
		}
	}
}
int main(){
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		memset(board, 0, sizeof(board));
		memset(visited, false, sizeof(visited));
		for (int i = 1; i <= n; i++) {
			scanf("%d%d%d", &board[i].first.first, &board[i].first.second, &board[i].second);
		}
		a.clear();
		a.resize(n + 1);
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				if (i == j) continue;
				else {
					int x = board[i].first.first - board[j].first.first;
					int y = board[i].first.second - board[j].first.second;
					double dist = (double)sqrt(x*x+y*y);
					double range = (double)board[i].second +(double)board[j].second;
					if (range >= dist) {
						a[i].push_back(j);
						a[j].push_back(i);
					}
				}
			}
		}
		int group = 0;
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				dfs(i);
				group++;
			}
		}
		printf("%d\n", group);
	}
	return 0;
}