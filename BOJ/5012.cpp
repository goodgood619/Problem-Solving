#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <utility>
using namespace std;
typedef long long ll;
int n;
#define INF 99999999
vector<ll> seg;
int h = 1;
ll arr[100005];
ll minnum[100005];
ll maxnum[100005];
void update(int index, ll value) {
	index += h - 1;
	seg[index] += value;
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
int main() {
	scanf("%d", &n);
	while (h < n) h *= 2;
	seg.resize(h * 2);
	for (int i = 1; i <= n; i++) {
		int num;
		scanf(" %d", &num);
		arr[i] = num;
	}
	for (int i = 1; i <= n; i++) {
		maxnum[i] = query(1,arr[i]+1,n,1,h);
		update(arr[i], 1);
	}
	seg.clear();
	seg.resize(h * 2);
	for (int i = n; i >= 1; i--){
		minnum[i] = query(1, 1, arr[i] - 1, 1, h);
		update(arr[i], 1);
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += maxnum[i] * minnum[i];
	}
	printf("%lld\n", ans);
	return 0;
}