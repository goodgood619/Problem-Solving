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
int a,b,n, m;
PP robot[105];
int board[105][105];
int main() {
	scanf("%d%d", &a, &b);
	int no = 0;
	// b가 가로,a는 세로
	// b는 4,a는 5
	// (1,3)->(4,3)
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int first, second;
		char dir;
		scanf(" %d %d %c", &first, &second,&dir);
		int x = b - second+1;
		int y = first;
		board[x][y] = i;
		int r = 0;
		if (dir == 'E') {
			r = 0;
		}
		else if (dir == 'S') {
			r = 1;
		}
		else if (dir == 'W') {
			r = 2;
		}
		else r = 3;
		robot[i].first.first = x;
		robot[i].first.second = y;
		robot[i].second = r;
	}
	// 동->L : 북, 북->L:서, 서->L:남, 남->L:동
	// 동->R: 남, 남->R:서, 서->R:북, 북->R:동
	// 0:동,1:남,2:서,3:북
	for (int i = 1; i <= m; i++) {
		if (no) break;
		int num, cnt;
		char c;
		scanf(" %d %c %d", &num, &c, &cnt);
		if (c == 'L') {
			cnt %= 4;
			int p = robot[num].second;
			for (int j = 1; j <= cnt; j++) {
				p--;
				if (p < 0) p = 3;
			}
			robot[num].second = p;
		}
		else if (c == 'R') {
			cnt %= 4;
			int p = robot[num].second;
			for (int j = 1; j <= cnt; j++) {
				p++;
				if (p == 4) p = 0;
			}
			robot[num].second = p;
		}
		else {
			int x = robot[num].first.first;
			int y = robot[num].first.second;
			int sx = x;
			int sy = y;
			int dir = robot[num].second;
			int rcnum = 0;
			bool crush = false;
			bool robotcrush = false;
			for (int j = 1; j <= cnt; j++) {
				int nx = x + gox[dir];
				int ny = y + goy[dir];
				if (nx<1 || nx>b || ny<1 || ny>a) {
					crush = true;
					no = 1;
					break;
				}
				if (board[nx][ny]!=0) {
					no = 1;
					rcnum = board[nx][ny];
					robotcrush = true;
					break;
				}
				x = nx;
				y = ny;
			}
			board[sx][sy] = 0;
			robot[num].first.first = x;
			robot[num].first.second = y;
			board[x][y] = num;
			if (crush) {
				printf("Robot %d crashes into the wall\n", num);
				break;
			}
			if (robotcrush) {
				printf("Robot %d crashes into robot %d\n", num, rcnum);
				break;
			}
		}
	}
	if (!no) {
		printf("OK\n");
	}
	return 0;
}