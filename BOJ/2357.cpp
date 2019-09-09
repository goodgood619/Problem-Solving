#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

ll n, m, h = 1, a, b, INF = 1e10, tmp;
vector <pair<ll, ll>> v;
pair<ll, ll> ans;
void update(ll Index, ll num) {
	Index += h - 1;
	v[Index] = { num,num };
	while (Index > 1) {
		Index /= 2;
		v[Index].first = min(v[Index * 2].first, v[Index * 2 + 1].first);
		v[Index].second = max(v[Index * 2].second, v[Index * 2 + 1].second);
	}
}

void query(ll L, ll R, ll nodeNum, ll nodeL, ll nodeR) {
	if (L <= nodeL && nodeR <= R) {
		ans.first = min(ans.first, v[nodeNum].first);
		ans.second = max(ans.second, v[nodeNum].second);
		return;
	}
	else if (nodeR < L || R < nodeL) return;
	ll mid = (nodeL + nodeR) / 2;
	query(L,R,nodeNum * 2,nodeL,mid),query(L,R,nodeNum * 2 + 1,mid + 1,nodeR);
}

int main() {
	scanf("%lld %lld", &n, &m);
	while (n > h) h <<= 1;
	v.resize(h * 2);
	for (int i = 0; i < v.size(); i++) {
		v[i].first = INF;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &tmp);
		update(i, tmp);
	}
	for (int i = 0; i < m; i++) {
		scanf("%lld %lld", &a, &b);
		ans = pair<ll,ll>(INF,0);
		query(a, b, 1, 1, h);
		printf("%lld %lld\n", ans.first, ans.second);
	}
}