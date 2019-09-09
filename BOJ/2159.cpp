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
typedef pair<ll,ll> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
typedef pair<pair<double, double>, pair<double, double>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n;
ll dp[100005][5];
P arr[100005];
ll dist(ll x1, ll y1, ll x2, ll y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}
ll go(ll hx,ll hy,int index, int dir) {
	if (index >= n) return 0;
	ll &ret = dp[index][dir];
	if (ret != -1) return ret;
	ret = 1e14;
	ret = min(ret, go(arr[index+1].first,arr[index+1].second,index + 1, 4) + dist(hx,hy,arr[index+1].first,arr[index+1].second)); // 그 위치로 이동하는경우
	ll x = arr[index+1].first, y = arr[index+1].second;
	for (int i = 0; i < 4; i++) {
		ll nx = x + gox[i];
		ll ny = y + goy[i];
		if (nx > 100000 || ny > 100000 || nx <= 0 || ny <= 0) continue; //인접한곳이 격자판위를 벗어나는경우
		ret = min(ret, go(nx,ny,index + 1, i) + dist(hx,hy, nx, ny)); // 인접한곳으로 이동하는경우
	}
	return ret;
}
int main() {
	scanf(" %d", &n);
	for (int i = 0; i <= n; i++) {
		scanf(" %lld %lld", &arr[i].first, &arr[i].second);
	}
	memset(dp, -1, sizeof(dp));
	printf("%lld\n", go(arr[0].first,arr[0].second,0, 4));
	return 0;
}