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
char board[505][505];
bool visited[505][505];
int n, m;
queue<P> q;
int no;
void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx<1 || nx>n || ny<1 || ny>m || visited[nx][ny] || board[nx][ny] == 'S' || board[nx][ny]=='D') continue;
			if (board[nx][ny] == 'W') {
				no = 1;
				return;
			}
			if (!visited[nx][ny]) {
				visited[nx][ny] = true;
				board[nx][ny] = 'D';
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &board[i][j]);
			if (board[i][j] == 'S') q.push({ i,j });
		}
	}
	bfs();
	if (no) printf("0\n");
	else {
		printf("1\n");
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				printf("%c", board[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}