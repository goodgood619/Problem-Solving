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
char board[1505][1505];
bool visited[1505][1505];
bool rvisit[1505][1505];
int height[1505][1505];
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n, m, sx, sy, ex, ey;
typedef pair<int, int> P;
int remove(char board[1505][1505]){
	int cnt = 1;
	queue<P> rq;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (board[i][j] == '.' || board[i][j]=='L') rq.push({ i,j });
		}
	}
	while (!rq.empty()){
		int turn = rq.size();
		for (int i = 0; i < turn; i++) {
			int x = rq.front().first;
			int y = rq.front().second;
			rq.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + gox[i];
				int ny = y + goy[i];
				if (nx<1 || nx>n || ny<1 || ny>m || rvisit[nx][ny]) continue;
				else if (!rvisit[nx][ny] && board[nx][ny] != 'L') {
					height[nx][ny] = cnt;
					rvisit[nx][ny] = true;
					rq.push({ nx,ny });
				}
			}
		}
		cnt++;
	}
	return cnt-2;
}
int bfs(int x,int y,int day) {
	queue<P> q;
	q.push({ x,y });
	visited[x][y] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		if (x == ex && y == ey) {
			return 1;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx<1 || nx>n || ny<1 || ny>m || visited[nx][ny]) continue;
			else if (!visited[nx][ny] && height[nx][ny]<=day) {
				visited[nx][ny] = true;
				q.push({ nx,ny });
			}
		}
	}
	return 0;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %1c", &board[i][j]);
			if (board[i][j] == 'L') {
				if (sx == 0) {
					sx = i;
					sy = j;
				}
				else {
					ex = i;
					ey = j;
				}
			}
		}
	}
	int left = 0;
	int right = remove(board);
	while (left<=right){
		int mid = (left + right) / 2;
		int check = bfs(sx,sy,mid);
		if (check == 1) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
		memset(visited, false, sizeof(visited));
	}
	printf("%d\n",left);
	return 0;
}