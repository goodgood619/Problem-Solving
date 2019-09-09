#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
vector<ll> seg;
ll nodeindex[1000005];
ll h = 1;
ll ans,minnode;
#define INF 10000000000
void update(int index, ll value) {
	index += h - 1;
	seg[index] = value;
	nodeindex[index] = index-h+1;
	while (index > 1){
		index /= 2;
		if (seg[index * 2] < seg[index * 2 + 1]) {
			seg[index] = seg[index * 2];
			nodeindex[index] = nodeindex[index * 2];
		}
		else if (seg[index * 2] > seg[index * 2 + 1]) {
			seg[index] = seg[index * 2 + 1];
			nodeindex[index] =nodeindex[index * 2 + 1];
		}
		else if (seg[index * 2] == seg[index * 2 + 1]) {
			seg[index] = seg[index * 2];
			nodeindex[index] = nodeindex[index * 2];
		}
	}
}
ll query(ll nodenum, ll L, ll R, ll nodeleft, ll noderight) {
	if (nodeleft > R || noderight < L) return INF;
	else if (L <= nodeleft && noderight <= R){
		if (seg[nodenum] <=seg[minnode]){
			minnode = nodenum;
		}
		return seg[nodenum];
	}
	ll mid = (nodeleft + noderight) / 2;
	return min(query(nodenum * 2, L, R, nodeleft, mid), query(nodenum * 2 + 1, L, R, mid + 1, noderight));
}

void divide(int L, int R) {
	if (L > R) return;
	if (L < R) {
		minnode = h*4-1;
		ll leftans = query(1, L, R, 1, h)*(R - L + 1);
		ans = max(leftans, ans);
		ll mid = nodeindex[minnode];
		if (mid - 1 >= L){
			divide(L, mid - 1);
		}
		if (mid + 1 <= R && mid+1>L) {
			divide(mid + 1, R);
		}
	}
	else if (L == R) {
		ll leftans = query(1, L, R, 1, h);
		ans = max(leftans, ans);
		return;
	}
}
int main() {
	while (1) {
		h = 1;
		int n;
		ans = 0;
		minnode = 0;
		scanf(" %d", &n);
		if (n == 0) break;
		while (h < n) h *= 2;
		seg.clear();
		seg.resize(h *4);
		memset(nodeindex, 0, sizeof(nodeindex));
		for (int i = 1; i < seg.size(); i++) {
			seg[i] = INF;
			nodeindex[i] =h*2-1;
		}
		for (int i = 1; i <= n; i++) {
			ll num;
			scanf(" %lld", &num);
			update(i, num);
		}
		divide(1, n);
		printf("%lld\n", ans);
	}
	return 0;
}