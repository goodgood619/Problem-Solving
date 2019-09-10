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
typedef pair<int, pair<int, int>> PPP;
typedef pair<pair<double, double>, pair<double, double>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
vector<int> seg;
int h = 1;
int n;
P arr[100005];
void update(int index, int value) {
	index += h - 1;
	seg[index] = value;
	while (index > 1) {
		index /= 2;
		seg[index] = seg[index * 2] + seg[index * 2+1];
	}
}
int query(int nodenum, int nodeleft, int noderight, int left, int right) {
	if (noderight < left || right < nodeleft) return 0;
	else if (left <= nodeleft && noderight <= right) return seg[nodenum];
	int mid = (nodeleft + noderight) / 2;
	return query(nodenum * 2, nodeleft, mid, left, right) + query(nodenum * 2 + 1, mid + 1, noderight, left, right);
}
int main() {
	scanf("%d", &n);
	while (h < n) h *= 2;
	seg.resize(h * 2);
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		arr[i] = {num,i};
	}
	sort(arr + 1, arr + n + 1);
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		update(arr[i].second, 1);
		ans = max(ans, i - query(1, 1, h, 1, i));
	}
	printf("%d\n", ans);

	return 0;
}