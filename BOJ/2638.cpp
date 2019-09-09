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
#define mod 1000000009
typedef pair<int,int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = {0,1, -1,0 };
int goy[4] = {1,0, 0,-1 };
int n, m;
int board[103][103];
int bfs() {
	queue<P> q;
	int cnt = 0,ti=0;
	for(int t = 1;;t++) {
		queue<P> temp;
		q.push({ 0,0 });
		bool visited[103][103] = { false, };
		int dist[103][103] = { 0, };
		visited[0][0] = true;
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + gox[i];
				int ny = y + goy[i];
				if (nx<0 || nx>n + 1 || ny<0 || ny>m + 1 || visited[nx][ny]) continue;
				else if (board[nx][ny] == 0 && !visited[nx][ny]) {
					visited[nx][ny] = true;
					q.push({ nx,ny });
				}
				else if (board[nx][ny] == 1 && !visited[nx][ny]) {
					dist[nx][ny]++;
					if (dist[nx][ny] >= 2) {
						temp.push({ nx,ny });
						visited[nx][ny] = true;
					}
				}
			}
		}
		if (temp.size() == 0) break;
		cnt = temp.size();
		ti = t;
		while (!temp.empty()) {
			int x = temp.front().first;
			int y = temp.front().second;
			temp.pop();
			board[x][y] = 0;
		}
	}
	return ti;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %d", &board[i][j]);
		}
	}
	printf("%d\n", bfs());
	return 0;
}