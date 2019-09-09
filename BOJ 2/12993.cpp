#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
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
#define mod 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
ll x, y;
vector<ll> v;
bool dfs(ll mx,ll my,int depth) {
	if (mx == x && my == y) return true;
	if (v[depth] > max(x, y)) return false;

	mx += v[depth];
	if (dfs(mx, my, depth + 1)) return true;
	mx -= v[depth];
	my += v[depth];
	if (dfs(mx, my, depth + 1)) return true;
	my -= v[depth];
	return false;
}
int main() {
	scanf("%lld%lld", &x, &y);
	ll sum = x + y;
	ll cnt = 0;
	for (ll i = 0; i <=sum;) {
		i = pow(3, cnt);
		v.push_back(i);
		cnt++;
	}
	dfs(0,0,0) ? printf("1\n") : printf("0\n");
	return 0;
}