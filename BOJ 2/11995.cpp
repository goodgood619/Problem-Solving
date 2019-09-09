#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<ll, pair<ll, ll>> P;
typedef pair<ll, ll> PP;
priority_queue<P, vector<P>, greater<P>> pq;
vector<vector<PP>> a;
vector<P> aa;
ll parent[4100005];
ll arrx[2005];
ll arry[2005];
ll diffx[2005];
ll diffy[2005];
int n, m;
ll A, B;
ll find(ll u) {
	if (parent[u]==-1) return u;
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
	scanf("%lld%lld%d%d", &A, &B, &n, &m);
	a.resize((n + 1)*(m + 1) + 1);

	for (int i = 1; i <= n; i++) {
		scanf("%lld", &arrx[i]);
	}
	arrx[n + 1] = A;
	for (int i = 1; i <= m; i++) {
		scanf("%lld", &arry[i]);
	}
	arry[m + 1] = B;
	sort(arrx, arrx + n + 1);
	sort(arry, arry + m + 1);
	for (int i = 0; i <= n; i++) {
		diffx[i] = arrx[i + 1] - arrx[i];
	}
	for (int i = 0; i <= m; i++) {
		diffy[i] = arry[i + 1] - arry[i];
	}
	ll plus = m + 1;
	ll start = 1;
	for (int k = 1; k <= n + 1; k++) {
		ll vertex = start + plus * (k - 1);
		for (int j = 1; j <= m; j++) {
			ll cost = diffx[k - 1];
			aa.push_back({ cost,{vertex,vertex + 1} });
			vertex++;
		}
	}
	ll plus2 = 1;
	ll start2 = 1;
	for (int j = 1; j <= m + 1; j++) {
		ll vertex = start2 + plus2 * (j - 1);
		for (int i = 1; i <= n; i++) {
			ll cost = diffy[j - 1];
			ll next = vertex + m + 1;
			aa.push_back({ cost,{ vertex,next } });
			vertex = next;
		}
	}
	sort(aa.begin(), aa.end());
	memset(parent, -1, sizeof(parent));
	ll total = 0;
	for (int i = 0; i < aa.size(); i++) {
		ll cost = aa[i].first;
		ll here = aa[i].second.first;
		ll next = aa[i].second.second;
		if (uni(here, next)){
			total += cost;
		}
	}
	printf("%lld\n", total);
	return 0;
}