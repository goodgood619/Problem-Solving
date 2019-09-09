#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <functional>
using namespace std;
typedef pair<int, pair <int, int>> P;
#define INF 1<<30
int n, sum;
int cnt = 1;
int board[126][126];
int dp[126][126];
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
priority_queue<P, vector<P>, greater<P>> pq;
void dijk(){
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = INF;
		}
	}
	dp[1][1] = board[1][1];
	pq.push({ board[1][1], { 1,1}});
	while (!pq.empty()) {
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		int cost = pq.top().first;
		pq.pop();
		if (dp[x][y] < cost) continue;
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx<1 || nx>n || ny<1 || ny>n) continue;
			if (dp[nx][ny]>dp[x][y] + board[nx][ny]){
				dp[nx][ny] = dp[x][y] + board[nx][ny];
				pq.push({ dp[x][y] + board[nx][ny],{nx,ny} });
			}
		}
	}
}
int main() {
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				scanf(" %d", &board[i][j]);
			}
		}
		dijk();
		printf("Problem %d: %d\n",cnt,dp[n][n]);
		cnt++;
	}
	return 0;
}