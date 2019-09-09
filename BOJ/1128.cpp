#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;
struct bung {
	ll w;
	ll c;
}o[52];
int n;
ll maxw;
ll maxc = 0;
ll hapw[52], hapc[52];
bool fsort(bung a, bung b) {
	if (a.w != b.w) return a.w > b.w;
	else return a.c > b.c;
}
void solv(ll c, ll w, int i, bool sw) {
	if (maxc < c) maxc = c;
	if (w >= hapw[i]) {
		ll tmp;
		tmp = c + hapc[i];
		if (maxc < tmp) maxc = tmp;
		return;
	}
	if (sw && o[i].w == o[i-1].w) {
		solv(c, w, i + 1, sw);
		return;
	}
	if (w - o[i].w >= 0) solv(c + o[i].c, w - o[i].w, i + 1, false);
	solv(c, w, i + 1, true);
}
void _in() {
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%lld %lld", &o[i].w, &o[i].c);
	scanf("%lld", &maxw);
	std::sort(o, o + n, fsort);
	hapw[n - 1] = o[n - 1].w;
	hapc[n - 1] = o[n - 1].c;
	for (i = n-2; i >= 0; i--) {
		hapw[i] = hapw[i + 1] + o[i].w;
		hapc[i] = hapc[i + 1] + o[i].c;
	}
}
int main() {
	_in();
	solv(0, maxw, 0, 0);
	printf("%lld\n", maxc);
	return 0;
}