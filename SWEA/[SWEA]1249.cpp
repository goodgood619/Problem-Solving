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
using namespace std;
typedef long long ll;
#define INF 1000000000
typedef pair<int,int> P;
typedef pair<pair<int, int>,int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,0,-1 };
int goy[4] = { 1,0,-1,0 };
int dist[100][100];
int board[100][100];
bool visited[100][100];
int n;
void bfs(int x,int y) {
	queue<P> q;
	q.push({ x,y });
	dist[x][y] = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (dist[nx][ny] > dist[x][y] + board[nx][ny]) {
				dist[nx][ny] = dist[x][y] + board[nx][ny];
				q.push({ nx,ny });
			}
		}
	}
}
int main() {
	int t;
	int Case = 1;
	scanf("%d", &t);
	while (t--) {
		memset(board, 0, sizeof(board));
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				dist[i][j] = 1e9;
			}
		}
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf(" %1d", &board[i][j]);
			}
		}
		bfs(0, 0);
		printf("#%d %d\n", Case++,dist[n-1][n-1]);
	}
	return 0;
}