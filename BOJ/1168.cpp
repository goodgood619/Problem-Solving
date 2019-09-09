
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
typedef pair<int, int> P;
typedef pair<pair<ll, ll>, ll> PP;
typedef pair<ll, pair<ll, ll >> PPP;
typedef pair<pair<ll, ll>, pair<ll, ll>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
vector<int> seg;
int h = 1;
int n, m;
void update(int index, int value) {
	index += h - 1;
	seg[index] = value;
	while (index > 1) {
		index /= 2;
		seg[index] = seg[index * 2] + seg[index * 2 + 1];
	}
}
int query(int nodenum, int nodeleft, int noderight, int left, int right) {
	if (noderight < left || right < nodeleft) return 0;
	else if (left <= nodeleft && noderight <= right) return seg[nodenum];
	int mid = (nodeleft + noderight) / 2;
	return query(nodenum * 2, nodeleft, mid, left, right) + query(nodenum * 2 + 1, mid + 1, noderight, left, right);
}

int find(int k, int nodenum,int nodeleft, int noderight) {
	if (nodeleft == noderight) return nodeleft;
	int value = seg[nodenum * 2];
	int mid = (nodeleft + noderight) / 2;
	if (k <= value) {
		return find(k, nodenum * 2, nodeleft, mid);
	}
	else {
		return find(k-value, nodenum * 2 + 1, mid + 1, noderight);
	}
}
int main() {
	scanf("%d%d", &n, &m);
	while (h < n) h *= 2;
	seg.resize(h * 2);
	for (int i = 1; i <= n; i++) update(i, 1);
	vector<int> ans;
	ans.push_back(m);
	update(m, 0);
	int mod = n - 1;
	for (int i = 2; i <= n; i++) {
		int sum = (query(1, 1, h, 1, ans.back())+m)%mod;
		if (sum == 0) sum = mod;
		int idx2 = find(sum,1,1,h);
		ans.push_back(idx2);
		update(idx2, 0);
		mod--;
	}
	printf("<");
	for (int i = 0; i < ans.size(); i++) {
		if (i == ans.size() - 1) printf("%d>\n",ans[i]);
		else printf("%d, ", ans[i]);
	}

	return 0;
}