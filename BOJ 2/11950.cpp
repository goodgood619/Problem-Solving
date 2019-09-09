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
int gox[4] = { -1,1,1,-1 };
int goy[4] = { 1,1,-1,-1 };
int n, m;
char board[51][51];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &board[i][j]);
		}
	}
	int sum = 0;
	for (int i = 1; i <= m; i++) {
		sum += (board[1][i] != 'W');
	}
	for (int i = 1; i <= m; i++) {
		sum += (board[n][i] != 'R');
	}
	int ans = 1e9;
	for (int i = 2; i <= n - 1; i++) { //i번째줄이 파랑색이라고 가정하자
		int white = 0;
		for (int j = 2; j < i; j++) {
			for (int k = 1; k<= m; k++) {
				if (board[j][k] != 'W')white++;
			}
		}
		int t = 0;
		int temp = 1e9;
		while (1) {
			int blue = 0, red = 0;
			if (i > n - 1 - t) break;
			for (int j = i; j <= n - 1-t; j++) { // 파랑색
				for (int k = 1; k <= m; k++) {
					if (board[j][k] != 'B') blue++;
				}
			}
			for (int j = n - t; j < n;j++) { // 빨강색
				for (int k = 1; k <= m; k++) {
					if (board[j][k] != 'R') red++;
				}
			}
			t++;
			ans = min(ans, sum + white +blue+red);
		}
	}
	printf("%d\n", ans);
	return 0;
}