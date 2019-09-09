#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;
int n;
ll up[500003];
ll numindex[1000005];
map<ll,ll> m;
int h = 1;
vector<ll> seg;
void update(int index, ll value) {
	index += h - 1;
	seg[index] = 1;
	while (index > 1) {
		index /= 2;
		seg[index] = seg[index * 2] + seg[index * 2 + 1];
	}
}
ll query(int nodenum, int L, int R, int nodeleft, int noderight) {
	if (nodeleft > R || noderight < L) return 0;
	else if (L <= nodeleft && noderight <= R) return seg[nodenum];
	int mid = (nodeleft + noderight) / 2;
	return query(nodenum * 2, L, R, nodeleft, mid) + query(nodenum * 2 + 1, L, R, mid + 1, noderight);
}
int main(){
	scanf("%d", &n);
	while (h < n) h *= 2;
	seg.resize(h * 2);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &up[i]);
	}
	for (int i = 1; i <= n; i++) {
		ll num;
		scanf("%lld", &num);
		numindex[num] = i;
	}
	ll total = 0;
	for (int i = 1; i <= n; i++) {
		ll index = numindex[up[i]];
		update(index, 1);
		ll ans = query(1, index + 1, h, 1, h);
		total += ans;
	}
	printf("%lld\n", total);
	return 0;
}