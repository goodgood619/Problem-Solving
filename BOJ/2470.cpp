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
int gox[8] = { 0,1,-1,0,1,1,-1,-1 };
int goy[8] = { 1,0,0,-1,1,-1,1,-1 };
int n;
vector<ll> v;
bool compare(const ll &a, const ll &b) {
	if (a != b) return abs(a) < abs(b);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		ll num;
		scanf("%lld", &num);
		v.push_back(num);
	}

	sort(v.begin(), v.end(),compare);
	ll Min = 1e14;
	ll a = 0, b = 0;
	for (int i = 0; i < v.size()-1; i++) {
		if (Min > abs(v[i] + v[i + 1])) {
			Min = abs(v[i] + v[i + 1]);
			a = v[i];
			b = v[i + 1];
		}
	}
	if (a > b) swap(a, b);
	printf("%lld %lld\n", a, b);
	return 0;
}