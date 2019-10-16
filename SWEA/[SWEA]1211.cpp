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
int t,ok;
int Case = 1;
int board[101][101];
bool visited[101][101];
int dist[101][101];
void bfs(int x,int y) {
	queue<P> q;
	memset(visited, false, sizeof(visited));
	memset(dist, 0, sizeof(dist));
	q.push({ x,y });
	visited[x][y] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (board[x][y] == 1 && y < 99 && board[x][y + 1] == 1 && !visited[x][y+1]) {
			visited[x][y + 1] = true;
			dist[x][y + 1] = dist[x][y] + 1;
			q.push({ x,y + 1 });
		}
		else if (board[x][y] == 1 && y > 0 && board[x][y - 1] == 1 && !visited[x][y-1]) {
			visited[x][y - 1] = true;
			dist[x][y - 1] = dist[x][y] + 1;
			q.push({ x,y-1 });
		}
		else if (board[x][y] == 1 && x < 99 && board[x + 1][y] == 1 && !visited[x+1][y]) {
			visited[x + 1][y] = true;
			dist[x + 1][y] = dist[x][y] + 1;
			q.push({ x + 1,y });
		}
	}
}
int main() {
	int t = 10;
	while (t--) {
		int n;
		scanf("%d", &n);
		memset(board, 0, sizeof(board));
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				scanf(" %d", &board[i][j]);
			}
		}
		int Min = 1e9;
		int ans = 0;
		for (int i = 0; i < 100; i++) {
			if (board[0][i] == 1) {
				bfs(0,i);
				for (int j = 0; j < 100; j++) {
					if (board[99][j] == 1) {
						if (Min >= dist[99][j] && dist[99][j]>0) {
							Min = dist[99][j];
							ans = i;
						}
					}
				}
			}
		}
		printf("#%d %d\n", n, ans);
	}
	return 0;
}