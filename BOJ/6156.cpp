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
typedef pair<int,int> P;
typedef pair<pair<int, int>,int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int board[105][105];
int n, m, s;
vector<int> v;
void floyd() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (board[i][k] == 1 && board[k][j]==1) {
					board[i][j]=1;
				}
				else if (board[i][k] == -1 && board[k][j] == -1) {
					board[i][j] = -1;
				}
			}
		}
	}
}
int main() {
	scanf("%d%d", &n,&m);
	for (int i = 1; i <= m; i++) {
		int win, lose;
		scanf("%d%d", &win, &lose);
		board[win][lose] = 1;
		board[lose][win] = -1;
	}
	floyd();
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			if (board[i][j] == 1 || board[i][j] == -1) cnt++;
		}
		if (cnt == n - 1) ans++;
	}
	printf("%d\n", ans);
	return 0;
}
