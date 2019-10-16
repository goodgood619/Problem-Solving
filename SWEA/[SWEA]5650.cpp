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
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, n,Max,earn;
int Case = 1;
int board[105][105];
bool visited[105][105];
vector<vector<P>> wormhole;
//게임은 핀볼이 출발 위치로 돌아오거나, 
//블랙홀에 빠질 때 끝나게 되며, 점수는 벽이나 블록에 부딪힌 횟수가 된다. 
//(웜홀을 통과하는 것은 점수에 포함되지 않는다.)
// 되돌아오는것을 구현하는것이 조금 까다로울듯
P l(int x, int y, int dir, int sx, int sy) { //그냥 몇칸이동할수있는지만 구한다
	for (int i = 1;; i++) {
		int nx = x + i * gox[dir];
		int ny = y + i * goy[dir];
		if ((nx == sx && ny == sy) || board[nx][ny] == -1) return { 0,0 }; //처음위치이거나, 블랙홀이거나
		if (nx<1 || nx>n || ny<1 || ny>n) { //벽이므로 점수획득
			earn++;
			return { 1,i }; //(벽이니까, 종료가 아님)
		}
		if (board[nx][ny] == 0) continue;
		for (int k = 1; k <= 5; k++) { // 도형은 점수획득
			if (board[nx][ny] == k) {
				earn++;
				return { 1, i };
			}
		}
		for (int k = 6; k <= 10; k++) { //웜홀은 노획득
			if (board[nx][ny] == k) {
				return { 1,i };
			}
		}
	}
}
int check(int sx, int sy, int ex, int ey, int dir) { //되돌아오는지 안오는지의 유무
	if (dir == 0) {
		if (board[ex][ey] == 1 || board[ex][ey] == 2 || board[ex][ey] == 5) return 1;
		else return 0;
	}
	else if (dir == 1) {
		if (board[ex][ey] == 2 || board[ex][ey] == 3 || board[ex][ey] == 5) return 1;
		else return 0;
	}
	else if (dir == 2) {
		if (board[ex][ey] == 1 || board[ex][ey] == 4 || board[ex][ey] == 5) return 1;
		else return 0;
	}
	else {
		if (board[ex][ey] == 3 || board[ex][ey] == 4 || board[ex][ey] == 5) return 1;
		else return 0;
	}
}
//0: 동, 1:남,2:북,3:서
void move(int x, int y, int dir) {
	earn = 0;
	int mx = x, my = y;
	bool first = false;
	while (1) {
		if (board[mx][my] == -1 || (first && x == mx && y == my)) break;
		first = true;
		P length = l(mx, my, dir, x, y);
		if (length.first == 0) break;
		int tx = mx + length.second * gox[dir], ty = my + length.second * goy[dir];
		if (board[tx][ty] >= 1 && board[tx][ty] <= 5) { //간위치가 1~5
			int back = check(mx, my, tx, ty, dir);
			if (back == 1) {
				dir = 3 - dir;
			}
			else {
				if (dir == 0 & board[tx][ty] == 3) dir = 1;
				else if (dir == 0 && board[tx][ty] == 4) dir = 2;
				else if (dir == 1 && board[tx][ty] == 1) dir = 0;
				else if (dir == 1 && board[tx][ty] == 4) dir = 3;
				else if (dir == 2 && board[tx][ty] == 2) dir = 0;
				else if (dir == 2 && board[tx][ty] == 3) dir = 3;
				else if (dir == 3 && board[tx][ty] == 1) dir = 2;
				else if (dir == 3 && board[tx][ty] == 2) dir = 1;
			}
		}
		else if (board[tx][ty] >= 6 && board[tx][ty] <= 10) { //간위치가 웜홀(위치만 변경하고 방향은 그대로
			if (tx == wormhole[board[tx][ty]][0].first && ty == wormhole[board[tx][ty]][0].second) {
				int a = wormhole[board[tx][ty]][1].first;
				int b = wormhole[board[tx][ty]][1].second;
				tx = a, ty = b;
			}
			else {
				int a = wormhole[board[tx][ty]][0].first;
				int b = wormhole[board[tx][ty]][0].second;
				tx = a, ty = b;
			}
		}
		else if (board[tx][ty] == 0) { //간곳이 평지라면, 무조건 벽이었을것 -> 방향만 바뀜
			dir = 3 - dir;
		}
		mx = tx, my = ty;

	}
}
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		vector<P> start;
		wormhole.clear();
		wormhole.resize(11);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				scanf(" %d", &board[i][j]);
				if (board[i][j] == 0) {
					start.push_back({ i,j });
				}
				else if (board[i][j] >= 6 && board[i][j] <= 10) {
					wormhole[board[i][j]].push_back({ i,j });
				}
			}
		}
		Max = 0;
		for (int i = 0; i < start.size(); i++) {
			int sx = start[i].first, sy = start[i].second;
			for (int k = 0; k < 4; k++) {
				move(sx, sy, k);
				Max = max(Max, earn);
			}
		}
		printf("#%d %d\n", Case++, Max);
	}
	return 0;
}