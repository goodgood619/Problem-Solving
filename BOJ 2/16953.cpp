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
typedef pair<int, ll> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<pair<int,int>, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
ll a, b;
map<ll, int> m;
void bfs(ll start) {
	m[start] = 1;
	queue<ll> q;
	q.push(start);
	while (!q.empty()) {
		ll here = q.front();
		if (here == b) return;
		q.pop();
		for (int i = 0; i < 2; i++) {
			if (i == 0) {
				ll next = here * 2;
				if (next > b) continue;
				if (m.count(next) == 0) {
					m[next] = m[here] + 1;
					q.push(next);
				}
			}
			else {
				ll next = here * 10 + 1;
				if (next > b) continue;
				if (m.count(next) == 0) {
					m[next] = m[here] + 1;
					q.push(next);
				}
			}
		}
	}
}
int main() {
	scanf("%lld%lld", &a, &b);
	bfs(a);
	int ans = m[b];
	ans == 0 ? printf("-1\n") : printf("%d\n", ans);
	return 0;
}