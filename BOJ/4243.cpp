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
typedef pair<ll, ll> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t,n,st;
ll dp[105][105][2];
ll sum[105];
ll go(int i, int j, int k) {
	if (i == 1 && j == n) return 0;
	ll &ret = dp[i][j][k];
	if (ret != -1) return ret;
	ret = 1e12;
	ll ti = 0,wait=0;
	ll res = n - (j - i)-1; //남은 상점의 갯수!!!
	if (i - 1 >= 1) { //왼쪽으로 가자
		if (k == 0) {
			wait = sum[i] - sum[i - 1];
		}
		else {
			wait = sum[j] - sum[i - 1];
		}
		ret = min(ret, go(i- 1, j, 0) + res*wait);
	}
	if (j + 1 <= n) { //오른쪽으로 가자
		if (k == 0) {
			wait = sum[j + 1] - sum[i];
		}
		else {
			wait = sum[j + 1] - sum[j];
		}
		ret = min(ret, go(i, j + 1, 1) + res*wait);
	}
	return ret;
}
int main() {
	scanf("%d", &t);
	while (t--) {
		memset(dp, -1, sizeof(dp));
		memset(sum, 0, sizeof(sum));
		scanf("%d%d", &n, &st);
		for (int i = 2; i <= n; i++) {
			ll num;
			scanf("%lld", &num);
			sum[i] += sum[i - 1] + num;
		}

		printf("%lld\n", (go(st, st, 0)));

	}
	return 0;
}