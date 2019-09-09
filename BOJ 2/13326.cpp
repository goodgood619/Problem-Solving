#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>
#include <iostream>
#include <vector>
#include <list>
#include <math.h>
#include <functional>
#include <set>
#include <string>
#include <climits>
using namespace std;
typedef long long ll;
typedef pair<int, int> Pair;

int n, p1, p2, B, A[5001], x[5000], y[5000], idx[5000];
double ans = 2e9;

int go(Pair x, Pair y) {
	return (x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second);
}

int go(int a, int b) {
	return (x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]);
}

bool compare(int x, int y) {
	return go(p1, x) < go(p1, y);
}

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d %d", &x[i], &y[i]), idx[i] = i;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (go(p1, p2) < go(i, j)) p1 = i, p2 = j;
	sort(idx, idx + n, compare);
	for (int i = n - 1; i--;) {
		A[i] = A[i + 1];
		for (int j = n; --j > i;) A[i] = max(A[i], go(idx[i], idx[j]));
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) B = max(B, go(idx[i - 1], idx[j]));
		ans = min(ans, sqrt(A[i]) + sqrt(B));
	}
	printf("%f\n", ans);
}