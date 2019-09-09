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
int n, m;
P light[1005];
ll sum[1005];
ll dp[1005][1005][2]; // 구간 dp, (i~j까지 전등이 꺼졌을때, 로봇이 i,j에 있을때, 전등을 모두 끄는데 걸리는 최소 비용)
ll go(int i,int j,int k) {
	if (i == 1 && j == n) return 0; // 끝에 도달한경우
	ll &ret = dp[i][j][k];
	if (ret != -1) return ret;
	ret = 1e12;
	ll ti = 0;
	if (i - 1 >= 1) { //왼쪽으로 가기
		if (k == 0) ti = light[i].first - light[i - 1].first; //i에 위치 할경우
		else ti = light[j].first - light[i - 1].first; // j에 위치할경우
		ll total = ti * (abs(sum[i - 1] + sum[n] - sum[j]));
		ret = min(ret, go(i - 1, j, 0) + total);
	}
	if (j + 1 <= n) { //오른쪽으로 가기
		if (k == 0) ti = light[j + 1].first - light[i].first;
		else ti = light[j + 1].first - light[j].first;
		ll total = ti * (abs(sum[i - 1] + sum[n] - sum[j]));
		ret = min(ret, go(i, j + 1, 1) + total);
	}
	return ret;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld%lld", &light[i].first, &light[i].second);
		sum[i] += sum[i - 1] + light[i].second;
	}
	memset(dp, -1, sizeof(dp));
	printf("%lld\n", go(m, m, 0));
	return 0;
}