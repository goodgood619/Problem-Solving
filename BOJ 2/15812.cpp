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
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n, m;
int board[25][25];
bool visited[25][25];
bool visited2[25][25];
bool check[25][25];
int Min = 1e9;
vector<P> temp;
void bfs() {
	int dist[25][25] = { 0, };
	int sum = 0;
	memset(visited2, false, sizeof(visited2));
	queue<P> q;
	q.push({ temp[0].first,temp[0].second });
	q.push({ temp[1].first,temp[1].second });
	visited2[temp[0].first][temp[0].second] = true;
	visited2[temp[1].first][temp[1].second] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx<0 || nx>=n || ny<0 || ny>=m) continue;
			if (!visited2[nx][ny]) {
				visited2[nx][ny] = true;
				q.push({ nx,ny });
				dist[nx][ny] = dist[x][y] + 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (check[i][j] == true) sum=max(sum,dist[i][j]);
		}
	}

	Min = min(Min, sum);
	return;
}
void go(int x, int y, int cnt, int depth) {
	if (cnt == depth) {
		bfs();
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && board[i][j]==0) {
				visited[i][j] = true;
				temp.push_back({ i,j });
				go(i, j, cnt + 1, depth);
				temp.pop_back();
				visited[i][j] = false;
			}
		}
	}
	
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %1d", &board[i][j]);
			if (board[i][j] == 1) check[i][j] = true;
		}
	}

	go(0, 0, 0, 2);
	printf("%d\n", Min);
	return 0;
}
