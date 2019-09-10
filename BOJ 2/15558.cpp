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
using namespace std;
typedef long long ll;
int n, k;
int board[200005][3];
typedef pair<int, pair<int, int>> P;
queue<P> q;
bool visited[200005][3];
int gox[2] = { -1,1 };
bool check;
void bfs(int x, int y) {
	q.push({1,{x,y}});
	visited[x][y] = true;
	while (!q.empty()) {
		int turn = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();
		if (check) break;
		for (int i = 0; i < 3; i++) {
			if (i == 2) {
				int temp = y;
				if (temp == 1) temp = 2;
				else temp = 1;
				int nx = x + k;
				if (board[nx][temp] == 0 || visited[nx][temp] || turn >= nx || nx<0) continue;
				else {
					if (nx > n) {
						check = true;
					}
					visited[nx][temp] = true;
					q.push({ turn + 1,{nx,temp}});
				}
			}
			else{
				int nx = x + gox[i];
				if (board[nx][y] == 0 || visited[nx][y] || turn >=nx ||nx<0) continue;
				else {
					if (nx > n) {
						check = true;
					}
					visited[nx][y] = true;
					q.push({turn+1,{nx,y}});
				}
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &k);
	memset(board, 1, sizeof(board));
	for (int j = 1; j <= 2; j++) {
		for (int i = 1; i <= n; i++) {
			scanf("%1d", &board[i][j]);
		}
	}
	bfs(1, 1);
	if (check) printf("1\n");
	else printf("0\n");
	return 0;
}