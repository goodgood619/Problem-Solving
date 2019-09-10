
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
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<char, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, Case = 1,h=1;
vector<ll> seg;
void update(int index,ll value) {
	index += h - 1;
	seg[index] = value;
	while (index > 1) {
		index /= 2;
		seg[index] = seg[index * 2] + seg[index * 2 + 1];
	}
}
ll query(int nodenum,int nodeleft,int noderight,int left,int right) {
	if (nodeleft > right || noderight < left) return 0;
	else if (left <= nodeleft && noderight <= right) return seg[nodenum];
	int mid = (nodeleft + noderight) / 2;
	return query(nodenum * 2, nodeleft, mid, left, right) + query(nodenum * 2 + 1, mid + 1, noderight, left, right);
}
int main() {
	setbuf(stdout, NULL);
	int n, q;
	scanf("%d%d", &n, &q);
	while (h < n) h *= 2;
	seg.resize(h * 2);

	for (int i = 1; i <= n; i++) {
		ll num;
		scanf("%lld", &num);
		update(i, num);
	}
	for (int i = 1; i <= q; i++) {
		int choice;
		scanf("%d", &choice);
		if (choice == 1) {
			int left,right;
			scanf("%d%d", &left, &right);
			printf("%lld\n", query(1, 1, h, left, right));
			ll leftnum = seg[left + h - 1],rightnum=seg[right+h-1];
			update(left, rightnum);
			update(right, leftnum);
		}
		else {
			int l1, r1, l2, r2;
			scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
			printf("%lld\n", query(1, 1, h, l1, r1) - query(1, 1, h, l2, r2));
		}
	}
	return 0;
}
