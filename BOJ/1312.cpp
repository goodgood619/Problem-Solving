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
typedef pair<char, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, Case = 1, n, m,k;
int main() {
	setbuf(stdout, NULL);
	
	ll a, b, n;
	vector<ll> v;
	scanf("%lld%lld%lld", &a, &b, &n);
	if (a >= b) {
		a = a % b;
	}
	while (1) {
		if (v.size() == n) break;
		ll ahr = a / b;
		ll sk = a % b;
		if (ahr == 0) {
			a *= 10;
			ahr = a / b;
			sk = a % b;
			v.push_back(ahr);
			a = sk;
		}
		else {
			v.push_back(ahr);
			a = sk;
		}
	}
	printf("%lld\n", v[v.size() - 1]);
	return 0;
}