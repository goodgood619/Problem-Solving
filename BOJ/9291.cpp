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
int c[10];
bool go(int x, int y) {
	int sx = (x / 3) * 3;
	int sy = (y / 3) * 3;
	int Max = 0;
	memset(c, 0, sizeof(c));
	for (int i = sx; i < sx + 3; i++) {
		for (int j = sy; j < sy + 3; j++) {
			c[board[i][j]]++;
			Max = max(Max, c[board[i][j]]);
		}
		if (Max > 1) return false;
	}
	return true;
}
int main() {
	int t;
	scanf("%d", &t);
	int Case = 1;
	while (t--) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				scanf(" %d", &board[i][j]);
			}
		}
		bool no = false;
		for (int i = 0; i < 9; i++) {
			int cnt[10] = { 0, };
			int Max = 0;
			for (int j = 0; j < 9; j++) {
				cnt[board[i][j]]++;
				Max = max(Max, cnt[board[i][j]]);
			}
			if (Max > 1) {
				no = true;
				break;
			}
		}
		if (no) {
			printf("Case %d: INCORRECT\n",Case++);
			continue;
		}
		for (int j = 0; j < 9; j++) {
			int cnt[10] = { 0, };
			int Max = 0;
			for (int i = 0; i < 9; i++) {
				cnt[board[i][j]]++;
				Max = max(Max, cnt[board[i][j]]);
			}
			if (Max > 1) {
				no = true;
				break;
			}
		}
		if (no) {
			printf("Case %d: INCORRECT\n",Case++);
			continue;
		}
		for (int i = 0; i < 9; i += 3) {
			for (int j = 0; j < 9; j += 3) {
				if (go(i, j)) continue;
				else {
					no = true;
					break;
				}
			}
			if (no) break;
		}
		if (no) {
			printf("Case %d: INCORRECT\n", Case++);
			continue;
		}
		printf("Case %d: CORRECT\n", Case++);
	}
	return 0;
}