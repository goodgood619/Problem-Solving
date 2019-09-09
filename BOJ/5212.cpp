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
typedef pair<double, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<double, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { -1,0,1,0 };
int goy[4] = { 0,1,0,-1 };
int t, Case = 1,n,m;
char board[12][12];
bool visited[12][12];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i <= 11; i++) {
		for (int j = 0; j <= 11; j++) {
			board[i][j] = '.';
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &board[i][j]);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (board[i][j] == 'X') {
				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int nx = i + gox[k];
					int ny = j + goy[k];
					if (board[nx][ny] == '.' && !visited[nx][ny]) cnt++;
				}
				if (cnt >= 3) {
					board[i][j] = '.';
					visited[i][j] = true;
				}
			}
		}
	}
	int minx = 1e9, miny = 1e9, maxx = -1, maxy = -1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (board[i][j] == 'X') {
				minx = min(minx, i);
				maxx = max(maxx, i);
				miny = min(miny, j);
				maxy = max(maxy, j);
			}
		}
	}
	for (int i = minx; i <= maxx; i++) {
		for (int j = miny; j <= maxy; j++) {
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
	return 0;
}