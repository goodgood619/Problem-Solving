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
#define mod 1000000009
#define lim 1000000000
typedef pair <int, int > P;
typedef pair<int,pair<int, int>> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[8] = { 0,1,-1,0,1,1,-1,-1 };
int goy[8] = { 1,0,0,-1,-1,1,1,-1 };
int ans[51][51];
int board[51][51];
vector<P> v;
int n, m;
void bfs(int sx,int sy) {
	int dist[51][51] = { 0, };
	bool visited[51][51] = { false, };
	queue<P> q;
	q.push({ sx,sy });
	visited[sx][sy] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx<1 || nx>n || ny<1 || ny>m || visited[nx][ny] || board[nx][ny] == 1) continue;
			else if (!visited[nx][ny]) {
				visited[nx][ny] = true;
				q.push({ nx,ny });
				dist[nx][ny] = dist[x][y] + 1;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (dist[i][j]==0) continue;
			ans[i][j] = min(ans[i][j], dist[i][j]);
		}
	}
}
int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &board[i][j]);
			if (board[i][j] == 1) v.push_back({ i,j });
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ans[i][j] = 1e9;
		}
	}
	for (int i = 0; i < v.size(); i++) {
		bfs(v[i].first, v[i].second);
	}
	int Max=0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (ans[i][j] == 1e9) continue;
			Max = max(Max, ans[i][j]);
		}
	}
	printf("%d\n", Max);
	return 0;
}