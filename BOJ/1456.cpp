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
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
ll a, b;
bool check[10000005];
int main() {
	for (int i = 2; i <= sqrt(10000000); i++) {
		if (check[i]) continue;
		for (int j = i * i; j <= 10000000; j += i) {
			check[j] = true;
		}
	}
	vector<ll> v;
	for (int i = 2; i <= 10000000; i++) {
		if (!check[i]) v.push_back(i);
	}
	scanf("%lld%lld", &a, &b);
	vector<ll> ans;
	for (int i = 0; i < v.size(); i++) {
		ll here = v[i];
		if (here > b) break;
		for (int j = 2;powl(here,j)<=b;j++) {
			ll temp = powl(here, j);
			if (temp > b) break;
			ans.push_back(temp);
		}
	}
	sort(ans.begin(), ans.end());
	vector<ll>::iterator it;
	it = lower_bound(ans.begin(), ans.end(), a);
	printf("%d\n", ans.end() - it);
	return 0;
}