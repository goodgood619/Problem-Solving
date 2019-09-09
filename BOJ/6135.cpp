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
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int board[305][305];
int n, m, t;
vector<int> v;
void floyd() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (board[i][j]>max(board[i][k],board[k][j]) && board[i][k]!=1e9 &&  board[k][j]!=1e9) {
					board[i][j] = max(board[i][k],board[k][j]);
				}
			}
		}
	}
}
int main() {
	scanf("%d%d%d", &n, &m,&t);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			board[i][j] = 1e9;
		}
	}
	for (int i = 1; i <= m; i++) {
		int win, lose,cost;
		scanf("%d%d%d", &win, &lose,&cost);
		board[win][lose] = cost;
	}
	floyd();

	for (int i = 1; i <= t; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		if (board[first][second] == 1e9) printf("-1\n");
		else printf("%d\n", board[first][second]);
	}
	return 0;
}