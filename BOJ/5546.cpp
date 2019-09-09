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
#define mod 10000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int dp[105][5][4];
int pasta[105];
int n, k;
int go(int index,int eat,int right) {
	if (right >= 3) return 0;
	if (index >n) return 1;
	int &ret = dp[index][eat][right];
	if (ret != -1) return ret;
	ret = 0;
	if (pasta[index] != 0) { //그날 먹을것이 정해져있을때
		if (eat != pasta[index]) {
			ret += go(index + 1, pasta[index], 1);
			ret %= mod;
		}
		else {
			ret += go(index + 1, pasta[index], right + 1);
			ret %= mod;
		}
	}
	else { //정해져있지않을때
		for (int i = 1; i <= 3; i++) {
			if (eat != i) ret += go(index + 1, i, 1);
			else ret += go(index + 1, i, right + 1);
			ret %= mod;
		}
	}
	ret %= mod;
	return ret;
}
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= k; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		pasta[x] = y;
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n",go(1,0,0)%mod);
	return 0;
}