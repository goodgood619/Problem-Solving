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
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n, t;
ll dp[91][2];
ll go(int t,int num) {
	if (t == n) return 1;
	ll &ret = dp[t][num];
	if (ret != -1) return ret;
	ret = 0;
	if (num == 0) {
		ret += go(t + 1, (num + 1)%2);
		ret += go(t + 1, num % 2);
	}
	else ret += go(t + 1, 0);
	return ret;
}

int main() {
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	printf("%lld\n", go(1, 1));
	return 0;
}