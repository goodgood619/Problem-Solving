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
int gox[4] = { 1, 0,0,-1 };
int goy[4] = { 0, 1,-1,0 };
int board[25][25];
int newboard[25][25];
bool visited[25][25];
int n;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %d", &board[i][j]);
			newboard[i][j] = board[i][j];
		}
	}
	int ans = 0;
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i == k || k == j) continue;
				if (board[i][j] == board[i][k] + board[k][j]) {
					visited[i][j] = true;
				}
				else if (board[i][j] > board[i][k] + board[k][j]) {
					printf("-1\n");
					return 0;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (visited[i][j]) continue;
			ans += board[i][j];
		}
	}
	ans /= 2;
	ans == 0 ? printf("-1\n") : printf("%d\n", ans);
	return 0;
}