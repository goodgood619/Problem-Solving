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
int gox[4] = { -1,0,0,1 };
int goy[4] = { 0,1,-1,0 };
int t,n;
ll dp[77][11];
ll go(int index,int num) {
	if (index == n) return 1;
	ll &ret = dp[index][num];
	if (ret != -1) return ret;
	ret = 0;

	for (int i = 0; i < 10; i++) {
		if (num <= i) {
			ret += go(index + 1, i);
		}
	}
	return ret;
}
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		memset(dp, -1, sizeof(dp));
		printf("%lld\n", go(0,0));
	}
	return 0;
}