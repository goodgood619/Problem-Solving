#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
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
#define mod 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0};
int goy[4] = { 1,0,0,-1};
int n,m;
int board[105][105];
int path[105][105];
vector<int> route;
void go(int here, int en) {
	if (path[here][en] != 0) {
		go(here, path[here][en]);
		route.push_back(path[here][en]);
		go(path[here][en], en);
	}
}
int main() {
	scanf("%d%d", &n,&m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			board[i][j] = 1e9;
		}
	}
	for (int i = 1; i <= m; i++) {
		int first, second, cost;
		scanf("%d%d%d", &first, &second, &cost);
		board[first][second] = min(board[first][second],cost);
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (board[i][j] > board[i][k] + board[k][j]) {
					board[i][j] = board[i][k] + board[k][j];
					path[i][j] = k;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) printf("0 ");
			else printf("%d ", board[i][j]);
		}
		printf("\n");
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j || board[i][j]==1e9) printf("0\n");
			else {
				route.clear();
				route.push_back(i);
				go(i, j);
				route.push_back(j);
				printf("%d ", route.size());
				for (int i = 0; i < route.size(); i++) {
					printf("%d ", route[i]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}