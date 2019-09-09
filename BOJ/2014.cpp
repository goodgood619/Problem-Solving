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
int k, n;
int main() {
	scanf("%d%d", &k, &n);
	priority_queue<ll, vector<ll>, greater<>> pq;
	vector<ll> v;
	for (int i = 1; i <= k; i++) {
		ll num;
		scanf("%lld", &num);
		pq.push(num);
		v.push_back(num);
	}
	int cnt = 0;
	ll ans;
	while (!pq.empty()) {
		ll here = pq.top();
		pq.pop();
		cnt++;
		if (cnt == n) {
			ans = here;
			break;
		}
		for (int i = 0; i < v.size(); i++) {
			ll value = here*v[i];
			pq.push(value);
			if (here%v[i] == 0) {
				break;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}