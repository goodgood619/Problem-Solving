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
#define mod 1000000007
#define lim 1000000000
typedef pair < int, int > P;
typedef pair<pair<int, int>, int> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n, k;
map<pair<int, int>, int> m;
ll go(int n, int k) {
	if (n == k || k==0 || n==0) return 1;
	if (m.count({ n,k }) == 0) {
		ll ret = 0;
		ret += go(n - 1, k) + go(n - 1, k - 1);
		ret %= mod;
		m[{n, k}] = ret;
	}
	else {
		return m[{n, k}];
	}
	return m[{n,k}];
}
int main(void) {
	scanf("%d%d", &n, &k);
	printf("%lld\n", go(n, k)%mod);
	return 0;
}