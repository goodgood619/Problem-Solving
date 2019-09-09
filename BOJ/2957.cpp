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
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
map<int, int> m;
int n;
ll ans;
int main() {
	scanf("%d", &n);
	m[0] = -1, m[300001] = -1;
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		m[num] = -1;
		auto it = m.lower_bound(num);
		auto left = it;
		auto right = it;
		left--,right++;
		it->second = max(left->second, right->second) + 1;
		ans += it->second;
		printf("%lld\n", ans);
	}
	return 0;
}