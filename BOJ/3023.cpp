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
typedef pair<pair<int, int>, pair<int, int>> PP;
typedef pair<double, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
using namespace std;
char board[151][151];
char board2[151][151];
int n, m;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &board[i][j]);	
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = m + 1,k=m; j <= 2 * m; j++,k--) {
			board[i][j] = board[i][k];
		}
	}

	for (int i = n + 1,k=n; i <= 2 * n; i++,k--){
		for (int j = 1,p=1; j <= 2 * m; j++,p++){
			board[i][j] = board[k][p];
		}
	}
	int sx, sy;
	scanf("%d%d", &sx, &sy);
	if (board[sx][sy] == '.') board[sx][sy] = '#';
	else board[sx][sy] = '.';
	for (int i = 1; i <= 2 * n; i++) {
		for (int j = 1; j <= 2 * m; j++) {
			printf("%c", board[i][j]);
		}
		printf("\n");
	}
	return 0;
}