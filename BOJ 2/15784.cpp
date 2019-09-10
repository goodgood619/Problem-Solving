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
typedef pair<int, pair<int, int>> PP;
typedef pair<double, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n, a, b;
int board[1001][1001];
int main() {
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %d", &board[i][j]);
		}
	}
	int here = board[a][b];
	int no = 0;
	for (int i = 1; i <= n; i++) {
		if (board[a][i] > here) {
			no = 1;
			break;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (board[i][b] > here) {
			no = 1;
			break;
		}
	}
	no == 1 ? printf("ANGRY") : printf("HAPPY");
	return 0;
}