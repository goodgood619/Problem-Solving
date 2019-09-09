#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<ll, pair<ll, ll>> P;
vector<P> aa;
ll parent[2005];
ll tour[2005];
int n, m;
ll find(ll u) {
	if (parent[u] == -1) return u;
	return parent[u] = find(parent[u]);
}
int uni(ll a, ll b) {
	ll atop = find(a);
	ll btop = find(b);
	if (atop != btop) {
		parent[btop] = atop;
		return 1;
	}
	return 0;
}
int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &tour[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			ll here1 = tour[i];
			ll here2 = tour[j];
			ll what = here1 ^ here2;
			aa.push_back({ what,{i,j}});
		}
	}
	sort(aa.begin(), aa.end());
	memset(parent, -1, sizeof(parent));
	ll total = 0;
	for (int i = aa.size()-1; i>=0; i--) {
		ll cost = aa[i].first;
		ll here = aa[i].second.first;
		ll next = aa[i].second.second;
		if (uni(here, next)) {
			total += cost;
		}
	}
	printf("%lld\n", total);
	return 0;
}