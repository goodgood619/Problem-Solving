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
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n, m, k;
int h = 1;
vector<ll> seg;
void update(int index, ll value) {
	index += h - 1;
	seg[index]+= value;
	while (index > 1) {
		index /= 2;
		seg[index] = seg[index * 2] + seg[index * 2 + 1];
	}
}

ll query(int nodenum, int k,int nodeleft, int noderight) {
	if (nodeleft == noderight) return nodenum-h+1;
	int mid = (nodeleft + noderight) / 2;
	if (seg[nodenum * 2] < k) {
		return query(nodenum * 2 + 1, k - seg[nodenum * 2], mid + 1, noderight);
	}
	else { //왼쪽
		return query(nodenum * 2, k, nodeleft, mid);
	}
}
int main() {
	scanf("%d", &n);
	while (h < 1000000) h *= 2;
	seg.resize(h*2);
	for (int i = 1; i <= n; i++) {
		int what;
		scanf("%d", &what);
		if (what == 1) {
			int taste;
			scanf("%d", &taste);
			int ans= query(1, taste, 1, h);
			printf("%d\n", ans);
			update(ans, -1);
		}
		else {
			int index, value;
			scanf("%d%d", &index, &value);
			update(index, value);
		}
	}
	
	return 0;
}