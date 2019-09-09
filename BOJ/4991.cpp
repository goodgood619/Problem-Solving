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
typedef pair<int, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0};
int goy[4] = { 1,0,0,-1};
int n, m,here;
char board[25][25];
int dist[12][12];
int dp[12][1 << 12];
vector<PPP> v;
int bfs(int sx, int sy, int ex, int ey) {
	queue<P> q;
	int temp[25][25] = { 0, };
	bool visited[25][25] = { false, };
	visited[sx][sy] = true;
	q.push({ sx,sy });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		if (x == ex && y == ey) {
			return temp[x][y];
		}
		q.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + gox[k];
			int ny = y + goy[k];
			if (nx<1 || nx>n || ny<1 || ny>m || board[nx][ny] == 'x' || visited[nx][ny]) continue;
			if (!visited[nx][ny]) {
				visited[nx][ny] = true;
				q.push({ nx,ny });
				temp[nx][ny] = temp[x][y] + 1;
			}
		}
	}
	return 1e9;
}
int go(int index,int via) {
	if (via == (1 << here) - 1) {
		return 0;
	}
	int &ret = dp[index][via];
	if (ret != -1) return ret;
	ret = 1e9;
	for (int i = 0; i < here; i++) {
		if (i == index) continue; // 같으면 불가능
		if (!(via &(1 << i))) {
			ret = min(ret, go(i, via | (1 << i))+dist[i][index]);
		}
	}
	return ret;
}
int main() {
	while (1) {
		scanf("%d%d", &m, &n);
		if (m == 0 && n == 0) break;
		int start = -1;
		v.clear();
		memset(dist, 0, sizeof(dist));
		here = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				scanf(" %c", &board[i][j]);
				if (board[i][j] == 'o') {
					start = here;
					v.push_back({ here++,{ i,j } });
				}
				if (board[i][j] == '*') {
					v.push_back({ here++,{ i,j} });
				}
			}
		}
		int no = 0;
		for (int i = 0; i < v.size(); i++) {
			for (int j = i + 1; j < v.size(); j++) {
				int d = bfs(v[i].second.first, v[i].second.second, v[j].second.first, v[j].second.second);
				if (d == 1e9) {
					no = 1;
					break;
				}
				dist[v[i].first][v[j].first] = d;
				dist[v[j].first][v[i].first] = d;
			}
			if (no) break;
		}
		if (no) {
			printf("-1\n");
			continue;
		}
		memset(dp, -1, sizeof(dp));
		printf("%d\n", go(start, (1 << start)));
	}
	return 0;
}