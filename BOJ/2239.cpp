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
typedef pair<int, int> P;
typedef pair<int, pair<int, int>> PP;
typedef pair<double, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int board[9][9];
bool go2(int x, int y, int num) {
	// 가로세로 검사
	for (int j = 0; j< 9; j++) {
		if (board[x][j] == num) return false;
	}
	for (int i = 0; i < 9; i++) {
		if (board[i][y] == num) return false;
	}
	int sx = (x / 3) * 3;
	int sy = (y / 3) * 3;
	for (int i = sx; i < sx + 3; i++) {
		for (int j = sy; j < sy + 3; j++) {
			if (board[i][j] == num) return false;
		}
	}
	return true;
}
void go() {
	int x=0, y=0;
	bool ok = false;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (board[i][j] == 0) {
				ok = true;
				x = i;
				y = j;
				break;
			}
		}
		if (ok) break;
	}
	if (!ok) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				printf("%d", board[i][j]);
			}
			printf("\n");
		}
		exit(0);
	}

	for (int i = 1; i <= 9; i++) {
		if (go2(x, y, i)) {
			board[x][y] = i;
			go();
			board[x][y] = 0;
		}
	}
}
int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf(" %1d", &board[i][j]);
		}
	}
	go();
	return 0;
}