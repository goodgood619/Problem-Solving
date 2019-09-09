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
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n;
vector<int> seg;
int h = 1;
int arr[100005];
int permutation[100005];
void update(int index, int value) {
	index += h - 1;
	seg[index] = value;
	while (index > 1) {
		index /= 2;
		seg[index] = seg[index * 2] + seg[index * 2 + 1];
	}
}
int query(int x,int nodenum, int nodeleft, int noderight) {
	int mid = (nodeleft + noderight) / 2;
	if (nodeleft == noderight) return nodeleft;
	if (x <= seg[nodenum * 2]) return query(x, nodenum * 2, nodeleft, mid);
	else return query(x - seg[nodenum * 2], nodenum * 2 + 1, mid + 1, noderight);
}
 int main() {
	scanf("%d", &n);
	while (h < n) h <<= 1;
	seg.resize(h * 2);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i <= n; i++) {
		update(i, 1);
	}
	for (int i = 1; i <= n; i++) {
		int index=query(arr[i]+1,1, 1, h);
		permutation[index] = i;
		update(index, 0);
	}
	for (int i = 1; i <= n; i++) {
		printf("%d\n", permutation[i]);
	}
	return 0;
}