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
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
// 0:오른쪽(동쪽), 1:남쪽,2:북쪽,3:서쪽 
int n, k, l,sx=1,sy=1;
int board[105][105];
vector<pair<int, char>> order;
list<P> snake;
int go() {
	snake.push_front({ sx,sy });
	int dir = 0;
	int x = 1, y = 1;
	board[1][1] = 3;
	int idx = 0;
	int ans = 0;
	for (int i = 1;; i++) {
		int nx = x + gox[dir];
		int ny = y + goy[dir];
		if (nx<1 || nx>n || ny<1 || ny>n || board[nx][ny] == 3) {
			ans = i;
			break;
		}
		if (board[nx][ny] == 1) {
			snake.push_front({ nx,ny }); //사과를 먹고
			board[nx][ny] = 3; // 뱀방문체크
		}
		else { //평지니까 줄어야함(꼬리쪽하나줄고)
			snake.push_front({ nx,ny });
			board[nx][ny] = 3;
			board[snake.back().first][snake.back().second] = 0;
			snake.pop_back();
		}

		if (idx < order.size() && order[idx].first == i) { //방향전환해야할때
			if (order[idx].second == 'L') {
				if (dir == 0) dir += 2;
				else if (dir == 1) dir = 0;
				else if (dir == 2) dir++;
				else if (dir == 3) dir = 1;
			}
			else {
				if (dir == 0) dir = 1;
				else if (dir == 1) dir = 3;
				else if (dir == 2) dir = 0;
				else if (dir == 3) dir = 2;
			}
			x = nx, y = ny;
			idx++;
		}
		else { //그렇지않을때
			x = nx, y = ny;
		}
	}
	return ans;
}
int main(void) {
	scanf(" %d%d", &n, &k);
	for (int i = 1; i <= k; i++) {
		int x, y;
		scanf(" %d%d", &x, &y);
		board[x][y] = 1;
	}

	scanf(" %d", &l);
	for (int i = 1; i <= l; i++) {
		int ti;
		char c;
		scanf(" %d %c", &ti, &c);
		order.push_back({ ti,c });
	}
	printf("%d\n", go());
	return 0;
}