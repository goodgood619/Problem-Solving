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
using namespace std;
typedef long long ll;
#define INF 1000000000
#define mod 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n, m;
vector<int> seg;
int h = 1;
void update(int index, int num) {
	index += h - 1;
	seg[index] = num;
	while (index > 1) {
		index /= 2;
		seg[index] = seg[index * 2] + seg[index * 2 + 1];
	}
}
int query(int nodenum, int l, int r, int nl, int nr) {
	if (r<nl || l>nr) return 0;
	else if (l <= nl && nr <= r) return seg[nodenum];
	int mid = (nl + nr) / 2;
	return query(nodenum * 2, l, r, nl, mid) + query(nodenum * 2 + 1, l, r, mid + 1, nr);
}
int main() {
	scanf("%d", &n);
	while (h < n) h *= 2;
	seg.resize(h * 2);
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		update(i, num);
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		int left, right;
		scanf("%d%d", &left, &right);
		printf("%d\n", query(1, left, right, 1, h));
	}
	return 0;

}
