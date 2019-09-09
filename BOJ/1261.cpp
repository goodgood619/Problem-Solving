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
typedef pair < int,int > P;
typedef pair<int,pair<int, int>> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = {-1,0,1,0 };
int goy[4] = {0,1,0,-1 };
int m, n;
char board[105][105];
void dijk(int x,int y) {
	priority_queue<PP, vector<PP>, greater<PP>> pq;
	pq.push({ 0,{x,y} });
	int dist[105][105] = { 0, };
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dist[i][j] = 1e9;
		}
	}
	dist[1][1] = 0;
	while (!pq.empty()) {
		int cost = pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();
		if (cost > dist[x][y]) continue;
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx<1 || nx>n || ny<1 || ny>m) continue;
			if (board[nx][ny] == '1') {
				if (dist[nx][ny] > dist[x][y] + 1) {
					dist[nx][ny] = dist[x][y] + 1;
					pq.push({ dist[nx][ny],{nx,ny} });
				}
			}
			else if(board[nx][ny]=='0'){
				if (dist[nx][ny] > dist[x][y]) {
					dist[nx][ny] = dist[x][y];
					pq.push({ dist[nx][ny],{nx,ny} });
				}
			}
		}
	}
	printf("%d\n", dist[n][m]);
}
int main(void) {
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &board[i][j]);
		}
	}
	dijk(1, 1);
	return 0;
}