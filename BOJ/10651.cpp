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
int n, m;
vector<ll> v;
ll dp[100005];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		ll here, speed;
		scanf("%lld%lld", &here, &speed);
		v.push_back(here + speed * m);
	}
	vector<ll> lis;
	lis.resize(n + 1);
	int en = 0;
	for (int i = v.size() - 1; i >= 0; i--) {
		ll *idx=upper_bound(dp + 1, dp + en + 1, v[i]);
		*idx = v[i];
		if (idx == dp + en + 1) en++;
	}
	printf("%d\n",en);
	return 0;
}