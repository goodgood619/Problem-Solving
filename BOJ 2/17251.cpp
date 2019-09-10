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
#define mod 1000000009
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<char, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, Case = 1;
typedef unsigned long long lll;
vector<int> seg;
int h = 1;
void update(int index,int value) {
	index += h - 1;
	seg[index] = value;
	while (index > 1) {
		index /= 2;
		seg[index] = max(seg[index * 2], seg[index * 2 + 1]);
	}
}
int query(int nodenum,int nodeleft,int noderight,int left,int right) {
	if (nodeleft > right || noderight < left) return 0;
	else if (left <= nodeleft && noderight <= right) return seg[nodenum];
	int mid = (nodeleft + noderight) / 2;
	return max(query(nodenum * 2, nodeleft, mid, left, right), query(nodenum * 2 + 1, mid + 1, noderight, left, right));
}
int main() {
	setbuf(stdout, NULL);
	int n;
	scanf("%d", &n);
	while (h < n) h *= 2;
	seg.resize(h * 2);
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		update(i, num);
	}
	int left = 0, right = 0,draw=0,lidx=1,ridx=2;
	for (int i = 1; i <= n; i++) {
		if (lidx >=n) break;
		int lmax = query(1, 1, h, 1, lidx);
		int rmax = query(1, 1, h, ridx, n);
		if (lmax > rmax) left++;
		else if (lmax < rmax) right++;
		else draw++;
		lidx++, ridx++;
	}
	if (left > right) printf("R\n");
	else if (left < right) printf("B\n");
	else printf("X\n");
	return 0;
}