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
	visited[x][y] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		if (x == 13 && y == 13) {
			dist[x][y] = 1;
			break;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx < 0 || nx >= 16 || ny < 0 || ny >= 16 || board[nx][ny]==1 || visited[nx][ny]) continue;
			if (!visited[nx][ny]) {
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
}
int main() {
	int t=10;
	int Case;
	while (t--) {
		memset(board, 0, sizeof(board));
		memset(visited, false, sizeof(visited));
		scanf("%d", &Case);
		for (int i = 0; i < 16; i++) {
			for (int j = 0; j <16; j++) {
				scanf(" %1d", &board[i][j]);
			}
		}
		bfs(1,1);
		int ok = 0;
		if (visited[13][13]) ok = 1;
		else ok = 0;
		printf("#%d %d\n", Case++,ok);
	}
	return 0;
}

