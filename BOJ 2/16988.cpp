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
typedef pair<int, int> P;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n, m, Max;
int board[22][22];
bool visited[405];
bool visited2[22][22];
vector<P> v, temp;
int bfs(int x, int y) {
	queue<P> q;
	q.push({ x,y });
	visited2[x][y] = true;
	int check = 0;
	int cnt = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		if (board[x][y] == 0) check = 1;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx<1 || nx>n || ny<1 || ny>m || visited2[nx][ny] || board[nx][ny] == 1) continue;
			else if (!visited2[nx][ny]) {
				visited2[nx][ny] = true;
				q.push({ nx,ny });
				if (board[nx][ny] == 2) cnt++;
			}
		}
	}
	if (check == 0) return cnt;
	else return 0;
}
void go(int index, int cnt, int depth) {
	if (cnt == depth) {
		int sum = 0;
		memset(visited2, false, sizeof(visited2));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (!visited2[i][j] && board[i][j] == 2) {
					int flag = bfs(i, j);
					if (flag == 0) continue;
					sum += flag;
				}
			}
		}
		Max = max(Max, sum);
		return;
	}
	for (int i = index; i < v.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			board[v[i].first][v[i].second] = 1;
			go(i + 1, cnt + 1, depth);
			board[v[i].first][v[i].second] = 0;
			visited[i] = false;
		}
	}
}
int main(void) {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %d", &board[i][j]);
			if (board[i][j] == 0) v.push_back({ i,j });
		}
	}

	go(0, 0, 2);
	printf("%d\n", Max);
	return 0;
}