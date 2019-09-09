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
int n;
ll dp[105][11][1 << 10];
ll go(int index, int num, int via) {
	if (num < 0 || num >= 10) return 0; // 끝까지 갔으므로 종료조건을 달아놓자
	if (index >= n-1 && (via | (1<<num)) == ((1 << 10) - 1)) return 1;
	if (index >= n-1) return 0;
	ll &ret = dp[index][num][via];
	if (ret != -1) return ret;
	ret = 0;
	via |= (1 << num);
	ret = ret + go(index + 1, num + 1, via) + go(index + 1, num - 1, via);
	ret %= INF;
	return ret;
}

int main() {
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	ll ans = 0;
	for (int i = 1; i < 10; i++) {
		ans += go(0, i, 0);
		ans %= INF;
	}
	printf("%lld\n", ans%INF);
	return 0;
}