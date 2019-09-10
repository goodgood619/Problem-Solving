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
using namespace std;
typedef long long ll;
#define INF 1000000000
typedef pair<int, int> P;
typedef pair<int, pair<ll, char>> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
typedef pair<ll, ll> p;
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
int n, m;
int main(){
	scanf("%d%d", &n, &m);
	ll left = 0;
	ll right = 1e14;
	vector<ll> v;
	for (int i = 1; i <= n; i++) {
		ll num;
		scanf("%lld", &num);
		v.push_back(num);
	}
	while (left <= right) {
		ll mid = (left + right) / 2;
		ll sum = 0;
		for (int i = 0; i < v.size(); i++) {
			sum += (mid / v[i]);
		}
		if (sum < m) left = mid + 1;
		else right = mid - 1;
	}
	printf("%lld\n", left);
	return 0;
}
