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
int n,m,q;
int board[255][255];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) board[i][j] = 1e9;
		}
	}
	for (int i = 1; i <= m; i++) {
		int left, right, t;
		scanf("%d%d%d", &left, &right, &t);
		if (t == 0) {
			board[left][right] = 0;
			board[right][left] = 1;
		}
		else {
			board[left][right] = 0, board[right][left] = 0;
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (board[i][j] > board[i][k] + board[k][j]) board[i][j] = board[i][k] + board[k][j];
			}
		}
	}
	scanf("%d", &q);
	for (int i = 1; i <= q; i++) {
		int left, right;
		scanf("%d%d", &left, &right);
		printf("%d\n", board[left][right]);
	}
	return 0;
}