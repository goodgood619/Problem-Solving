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
typedef pair<int,pair<int, int>> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
int n, m;
vector<vector<int>> a;
vector<int> v;
char board[55][55];
int row[55];
int col[55];
int main() {
	scanf("%d%d", &n, &m);
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %c", &board[i][j]);
			if (board[i][j] == 'X') {
				row[i]++;
				col[j]++;
			}
		}
	}
	int a = 0,b=0;
	for (int i = 1; i <= n; i++) {
		if (row[i] == 0) a++;
	}
	for (int j = 1; j <= m; j++) {
		if (col[j] == 0) b++;
	}
	printf("%d\n", max(a, b));
	return 0;
}