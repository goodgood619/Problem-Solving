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
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int board[105][105];
int n, m;
int go(int x, int y) {
	int sum = 0;
	for (int i = x; i < x + 3; i++) {
		for (int j = y; j < y + 3; j++) {
			sum += board[i][j];
		}
	}
	return sum;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %d", &board[i][j]);
		}
	}
	int Max = 0, idx = 0, idy = 0;
	for (int i = 1; i <= n - 2; i++) {
		for (int j = 1; j <= m - 2; j++) {
			if (Max < go(i, j)) {
				Max = go(i, j);
				idx = i, idy = j;
			}
		}
	}
	printf("%d\n%d %d\n", Max, idx, idy);
	return 0;
}