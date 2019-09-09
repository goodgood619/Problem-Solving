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
#define mod 1000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
ll dp[1005][2][3];
int n;
ll go(int index, int l, int r) {
	if (l == 2 || r == 3) return 0;
	if (index >= n) return 1;
	ll &ret = dp[index][l][r];
	if (ret != -1) return ret;
	ret = 0;
	ret += go(index + 1, l, 0); //결석은아닌데 지각은 안했다 -> 출석을했다라는 의미로 해석
	ret += go(index + 1, l + 1, 0);
	ret += go(index + 1, l,r+1);
	ret %= mod;
	return ret;
}
int main() {
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	printf("%lld\n",go(0, 0, 0)%mod);
	return 0;
}