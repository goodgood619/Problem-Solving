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
typedef pair < int,int > P;
typedef pair<int,pair<int, int>> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[5] = {0, -1,0,1,0 };
int goy[5] = {0, 0,1,0,-1 };
int t, Case = 1, m,k;
int board[11][11][11];
vector<int> amove, bmove;
int move() {
	int sx = 1, sy = 1, ex = 10, ey = 10,sum=0;
	for (int i = 0; i < amove.size(); i++) {
		sx += gox[amove[i]], sy += goy[amove[i]], ex += gox[bmove[i]], ey += goy[bmove[i]];
		int earn = 0;
		vector<int>make1, make2;
		for (int j = 1; j <= 8; j++) {
			if (board[j][sx][sy] != 0) make1.push_back(j);
		}
		for (int j = 1; j <= 8; j++) {
			if (board[j][ex][ey] != 0) make2.push_back(j);
		}

		for (int j = 0; j < make1.size(); j++) {
			earn = max(earn, board[make1[j]][sx][sy]);
		}
		for (int j = 0; j < make2.size(); j++) {
			earn = max(earn, board[make2[j]][ex][ey]);
		}
		for (int i = 0; i < make1.size(); i++) {
			for (int j = 0; j < make2.size(); j++) {
				int here1 = make1[i], here2 = make2[j];
				if (here1 == here2) {
					earn = max(earn, board[here1][sx][sy]);
				}
				else {
					earn = max(earn, board[here1][sx][sy] + board[here2][ex][ey]);
				}
			}
		}

		sum += earn;
	}
	return sum;
}
int main(void) {
	scanf("%d", &t);
	while (t--) {
		memset(board, 0, sizeof(board));
		amove.clear();
		bmove.clear();
		scanf("%d%d", &m, &k);
		amove.push_back(0), bmove.push_back(0);
		for (int i = 1; i <= m; i++) {
			int num;
			scanf("%d", &num);
			amove.push_back(num);
		}
		for (int i = 1; i <=m; i++) {
			int num;
			scanf("%d", &num);
			bmove.push_back(num);
		}

		for (int i = 1; i <= k; i++) {
			int y, x, cover, power;
			scanf("%d%d%d%d", &y, &x, &cover, &power);
			queue<PP> q;
			q.push({ 0,{x,y} });
			bool visited[15][15] = { false, };
			visited[x][y] = true;
			board[i][x][y] = power;
			while (!q.empty()) {
				int dist = q.front().first;
				int x = q.front().second.first;
				int y = q.front().second.second;
				board[i][x][y] = power;
				q.pop();
				if (dist == cover) continue;
				for (int i = 1; i <= 4; i++) {
					int nx = x + gox[i];
					int ny = y + goy[i];
					if (nx < 1 || nx>10 || ny < 1 || ny>10 || visited[nx][ny]) continue;
					else if (!visited[nx][ny]) {
						visited[nx][ny] = true;
						q.push({ dist + 1,{nx,ny} });
					}
				}
			}
		}
		printf("#%d %d\n", Case++,move());
	}
	return 0;
}