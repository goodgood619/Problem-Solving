#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <math.h>
#include <iostream>
#include <string>
using namespace std;
int n, m;
int h = 1;
typedef long long ll;
vector<ll> seg;
void update(int index, ll value) {
	index += h - 1;
	seg[index] = value;
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
	scanf("%d%d", &n, &m);
	while (h < n) h *= 2;
	seg.resize(h * 2);
	for (int i = 1; i <= m; i++) {
		int what;
		scanf("%d", &what);
		if (what == 1) {
			int index;
			ll value;
			scanf("%d%lld", &index, &value);
			update(index, value);
		}
		else if (what == 0){
			int left, right;
			scanf("%d%d", &left, &right);
			if (left > right) {
				int temp = left;
				left = right;
				right = temp;
			}
			ll ans=query(1, left, right, 1, h);
			printf("%lld\n", ans);
		}
	}
	return 0;
}