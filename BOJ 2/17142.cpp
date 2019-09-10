#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
#include <string>
#include <math.h>
#include <set>
#include <list>
#include <climits>
#include <string.h>
#include <deque>
#include <functional>
#include <stack>
using namespace std;
typedef long long ll;
#define INF 1000000000
#define mod 1000000007
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
int board[55][55];
int n, m, ans = 1e9;
bool visited[55];
vector<P> v, temp;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
bool check(int x, int y) {
	if (x == 1 && y == 1 || x == n && y == 1 || x == 1 && y == n || x == n && y == n) return true;
	else return false;
}
int bfs() {
	bool visited2[55][55] = { false, };
	int dist[55][55] = { 0, };
	queue<PP> q;
	for (int i = 0; i < temp.size(); i++) {
		visited2[temp[i].first][temp[i].second] = true;
		q.push({ { temp[i].first,temp[i].second }, 0 });
	}
	int Max = 0;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx<1 || nx>n || ny<1 || ny>n || visited2[nx][ny] || board[nx][ny] == 1) continue;
			else if (!visited2[nx][ny]) {
				visited2[nx][ny] = true;
				dist[nx][ny] = dist[x][y] + 1;
				if (board[nx][ny] == 0) {
					Max = max(Max, dist[nx][ny]);
				}
				q.push({ { nx,ny }, cnt + 1 });
			}
		}
	}
	int no = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!visited2[i][j] && board[i][j] == 0) {
				no = 1;
				break;
			}
		}
		if (no) break;
	}
	if (no) return 1e9 + 5;
	else return Max;
}
void dfs(int index, int cnt, int depth) {
	if (cnt == depth) {
		ans = min(ans, bfs());
		return;
	}

	for (int i = index; i < v.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			temp.push_back(v[i]);
			dfs(i + 1, cnt + 1, depth);
			temp.pop_back();
			visited[i] = false;
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %d", &board[i][j]);
			if (board[i][j] == 2)v.push_back({ i,j });
		}
	}
	if (m == 1) {
		printf("0\n");
		return 0;
	}
	dfs(0, 0, m);
	ans == 1e9 ? printf("-1\n") : printf("%d\n", ans);
	return 0;
}