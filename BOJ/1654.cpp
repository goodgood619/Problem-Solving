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
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n;
ll m;
vector<ll> v;
int main() {
	scanf("%d%lld", &n,&m);
	ll left = 1, right = 0;
	for (int i = 1; i <= n; i++) {
		ll num;
		scanf("%lld", &num);
		v.push_back(num);
		right = max(right, num);
	}

	while (left <= right) {
		ll mid = (left + right) / 2;
		ll cnt = 0;
		for (int i = 0; i < v.size(); i++) {
			cnt += (v[i] / mid);
		}
		if (cnt < m) right = mid - 1;
		else left = mid + 1;
	}
	printf("%lld\n", left-1);
	return 0;
}