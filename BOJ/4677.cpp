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
int gox[8] = { 0,1,-1,0,1,1,-1,-1 };
int goy[8] = { 1,0,0,-1,1,-1,1,-1 };
int n, m;
char board[105][105];
bool visited[105][105];
void bfs(int x, int y) {
	queue<P> q;
	q.push({ x,y });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx<1 || nx>n || ny<1 || ny>m || visited[nx][ny] || board[nx][ny]=='*') continue;
			if (!visited[nx][ny] && board[nx][ny] == '@') {
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
}
int main() {
	while (1) {
		scanf("%d%d", &n, &m);
		if (n == 0 && m == 0) break;
		memset(visited, false, sizeof(visited));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				scanf(" %c", &board[i][j]);
			}
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (!visited[i][j] && board[i][j] == '@') {
					bfs(i, j);
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}