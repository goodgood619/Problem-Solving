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
int gox[4] = {-1,1,0,0 };
int goy[4] = {0,0,-1,1 };
char board[50][50];
bool visited[50][50];
int n, m;
int go(int x, int y) {
	memset(visited, false, sizeof(visited));
	queue<PP> q;
	q.push({ { x,y }, 0 });
	visited[x][y] = true;
	int sum = 0;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dist = q.front().second;
		q.pop();
		sum = max(sum, dist);
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] == 'W' || visited[nx][ny]) continue;
			else if (!visited[nx][ny]) {
				visited[nx][ny] = true;
				q.push({ { nx,ny }, dist + 1 });
			}
		}
	}

	return sum;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %c", &board[i][j]);
		}
	}

	int Max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'L') {
				Max = max(Max, go(i, j));
			}
		}
	}
	printf("%d\n", Max);
	return 0;
}