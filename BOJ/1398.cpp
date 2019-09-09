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
int gox[4] = { 0,1,-1,0};
int goy[4] = { 1,0,0,-1};
int t;
ll n;
map<ll, ll> m;
vector<ll> v;
ll go(int n, ll k) {
	if (k == 0) return 0;
	if (k < 0) return 1e9;
	ll &ret = m[k];
	if (m[k] != 0) return ret;
	ret = 1e9;
	for (int i = v.size()-1; i >=0; i--) {
		if (k - v[i] >= 0) {
			ret = min(ret, go(n - 1, k - v[i])+1);
		}
	}
	return ret;
}
int main() {
	scanf("%d", &t);
	v.push_back(1);
	v.push_back(10);
	v.push_back(25);
	v.push_back(100);
	while (t--) {
		scanf("%lld", &n);
		ll ans = 0;
		while (n) {
			ll temp = n % 100;
			n /= 100;
			ans+=go(v.size() - 1,temp);
		}
		printf("%lld\n", ans);
	}
	return 0;
}