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
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n, m, t;
char board[205][205];
void bfs() {
	queue<P> q;
	int ti = 2;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (board[i][j] == 'O') q.push({ i,j });
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (board[i][j] != 'O') board[i][j] = 'O';
		}
	}
	while (ti < t) {
		queue<P> temp;
		bool visited[205][205] = { false, };
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			board[x][y] = '.';
			for (int i = 0; i < 4; i++) {
				int nx = x + gox[i];
				int ny = y + goy[i];
				if (nx<1 || nx>n || ny<1 || ny>m || visited[nx][ny]) continue;
				if (!visited[nx][ny]) {
					visited[nx][ny] = true;
					board[nx][ny] = '.';
				}
			}
		}
		ti++;
		if (ti == t) break;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (board[i][j] == 'O') {
					q.push({ i,j });
				}
			}
		}
		ti++;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (board[i][j] != 'O') {
					board[i][j] = 'O';
				}
			}
		}
		if (ti == t) break;
	}
}
int main() {
	scanf("%d%d%d", &n, &m, &t);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &board[i][j]);
		}
	}
	if (t % 2 == 0) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				printf("O");
			}
			printf("\n");
		}
		return 0;
	}
	if (t == 1) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				printf("%c", board[i][j]);
			}
			printf("\n");
		}
		return 0;
	}

	bfs();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
	return 0;
}