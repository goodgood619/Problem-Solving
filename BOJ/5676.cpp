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
vector<int> seg;
int h = 1;
int n,k;
#define mod 10007
void update(int index, int value) {
	index += h - 1;
	seg[index] = value;
	while (index > 1) {
		index /= 2;
		seg[index] = seg[index * 2] * seg[index * 2 + 1];
		seg[index] %= mod;
	}
}
int query(int nodenum, int left, int right, int nodeleft, int noderight) {
	if (left > noderight || right < nodeleft) return 1;
	else if (left <= nodeleft && noderight <= right) return seg[nodenum];
	int mid = (nodeleft + noderight) / 2;
	return query(nodenum * 2, left, right, nodeleft, mid)%mod*query(nodenum * 2 + 1, left, right, mid + 1, noderight)%mod;
}
int main() {
	while (scanf(" %d %d", &n, &k) != EOF) {
		seg.clear();
		h = 1;
		while (h < n) h *= 2;
		seg.resize(h * 2);
		vector<char> v;
		for (int i = 1; i <= n; i++) {
			int num;
			scanf("%d", &num);
			update(i, num);
		}
		for (int i = 1; i <= k; i++) {
			char c;
			scanf(" %c", &c);
			if (c == 'C') {
				int index, value;
				scanf("%d%d", &index, &value);
				update(index, value);
			}
			else {
				int left, right;
				scanf("%d%d", &left, &right);
				int ans = query(1, left, right, 1, h);
				if (ans > 0) v.push_back('+');
				else if (ans == 0) v.push_back('0');
				else v.push_back('-');
			}
		}
		for (int i = 0; i < v.size(); i++) printf("%c", v[i]);
		printf("\n");
	}
	
	return 0;
}