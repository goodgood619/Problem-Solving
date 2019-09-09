#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
vector <ll> seg;
int n, m, k; 
#define mod 1000000007
ll update(int index, int num, int nodeNum, int nodeleft, int noderight) {
	if (index<nodeleft || index>noderight) return seg[nodeNum]%mod;
	if (nodeleft == noderight) {
		seg[nodeNum] = num;
		return seg[nodeNum]%mod;
	}
	int mid = (nodeleft + noderight) / 2;
	seg[nodeNum] = ((update(index, num, nodeNum * 2, nodeleft, mid)%mod)*(update(index, num, nodeNum * 2 + 1, mid + 1, noderight)%mod)%mod);
	return seg[nodeNum]%mod;
}
ll query(int L, int R, int Nodenum, int nodeL, int nodeR) {
	if (nodeR < L || R < nodeL) return 1;
	if (L <= nodeL && nodeR <= R) return seg[Nodenum];
	int mid = (nodeL + nodeR) / 2;
	return (query(L, R, Nodenum * 2, nodeL, mid)%mod*query(L, R, Nodenum * 2 + 1, mid + 1, nodeR)%mod)%mod;
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	int h = 1;
	while (h < n) h *= 2;
	seg.resize(h * 2, 0);
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		update(i, num, 1, 1, h);
	}
	for (int i = 1; i <= m + k; i++) {
		int what, l, r;
		scanf("%d%d%d", &what, &l, &r);
		if (what == 1) {
			update(l, r, 1, 1, h);
		}
		else if (what == 2) {
			printf("%lld\n", query(l, r, 1, 1, h));
		}
	}
	return 0;
}