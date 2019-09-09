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
char board[51][51];
int Remove[5];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &board[i][j]);
		}
	}

	for (int i = 1; i <= n - 1; i++) {
		for (int j = 1; j <= m - 1; j++) {
			int cnt = 0;
			if (board[i][j] == '#' || board[i][j + 1] == '#' || board[i + 1][j] == '#' || board[i + 1][j + 1] == '#') continue;
			if (board[i][j] == 'X') cnt++;
			if (board[i][j + 1] == 'X') cnt++;
			if (board[i + 1][j] == 'X') cnt++;
			if (board[i + 1][j + 1] == 'X') cnt++;
			Remove[cnt]++;
		}
	}
	for (int i = 0; i < 5; i++) printf("%d\n", Remove[i]);
	return 0;
}