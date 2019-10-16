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
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t,n,m;
int main() {
	scanf("%d", &t);
	int Case = 1;
	while (t--) {
		scanf("%d%d", &n,&m);
		int board[25][25] = { 0, };
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				scanf(" %d", &board[i][j]);
			}
		}

		int cnt[25] = { 0, };
		for (int i = 1; i <= n; i++) {
			int sum = 0;
			for (int j = 1; j <= m; j++) {
				sum += (board[i][j] == 1);
			}
			cnt[i] = sum;
		}
		int Max = 0;
		for (int i = 1; i <= n; i++) {
			Max = max(Max, cnt[i]);
		}
		vector<int> v;
		for (int i = 1; i <= n; i++) {
			if (Max == cnt[i]) {
				v.push_back(i);
			}
		}
		printf("#%d %d %d\n", Case++,v.size(), Max);
	}
	return 0;
}