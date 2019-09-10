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
typedef pair < int, int > P;
typedef pair<int, pair<int, int>> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { -1,0,1,0 };
int goy[4] = { 0,1,0,-1 };
int board[700][700];
int a[350][350];
int h, w, x, y;
int main(void) {
	scanf("%d%d%d%d", &h, &w, &x, &y);
	for (int i = 0; i < h + x; i++) {
		for (int j = 0; j < w + y; j++) {
			scanf(" %d", &board[i][j]);
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			board[i + x][j + y] = board[i + x][j + y] - board[i][j];
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
	return 0;
}