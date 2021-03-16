#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int, pair<int, int>> P;
int gox[4] = {0,1,-1,0};
int goy[4] = {1,0,0,-1};
int dijk(vector<vector<int>>& board,int ex,int ey) {
	int sx = 0;
	int sy = 0;
	priority_queue<P, vector<P>, greater<P>> pq;
	vector<vector<int>> dist;
	dist.assign(ex + 1, vector<int>(ey + 1, 1e9));
	if (board[sx][sy] == -1) return -1;
	pq.push({ board[0][0],{0,0} });
	dist[0][0] = board[0][0];
	int ans = 0;
	while (!pq.empty()) {
		int cost = pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		if (x == ex && y == ey) {
			ans = dist[x][y];
			break;
		}
		pq.pop();
		if (cost > dist[x][y]) continue;
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx < 0 || nx >= ex + 1 || ny < 0 || ny >= ey + 1 || board[nx][ny] == -1) continue;
			if (dist[nx][ny] > cost+board[nx][ny]) {
				dist[nx][ny] = cost+board[nx][ny];
				pq.push({ dist[nx][ny],{nx,ny} });
			}
		}
	}

	if (ans == 0) return -1;
	return ans;
}
int main() {
	int n,m;
	scanf("%d%d", &n, &m);
	vector<vector<int>> board;
	board.assign(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	printf("%d\n",dijk(board,n-1,m-1));
	return 0;
}