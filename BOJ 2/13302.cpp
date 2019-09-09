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
typedef pair<int, ll> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n, m;
int dp[105][5][45];
int no[105];
int go(int index, int here, int c) {
	if (index >n) return 0;
	int &ret = dp[index][here][c];
	if (ret != -1) return ret;
	ret = 1e9;
	if (no[index] == 1) { //안되는날
		ret = min(ret, go(index + 1, here, c));
	}
	if (c >= 3) {  //쿠폰써서 공짜인날
		ret = min(ret, go(index + 1, here, c - 3));
	}
	ret = min(ret, go(index + 1, 1, c) + 10000);
	ret = min(ret, go(index + 3, 3, c+1) + 25000);
	ret = min(ret, go(index + 5, 5, c + 2) + 37000);
	return ret;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int num;
		scanf(" %d", &num);
		no[num]++;
	}

	memset(dp, -1, sizeof(dp));
	printf("%d\n",go(1, 0, 0));
	return 0;
}