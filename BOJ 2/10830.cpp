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
ll n,k;
typedef vector<vector<ll>> matrix;
matrix operator * (const matrix &a, const matrix &b) {
	int n = a.size();
	matrix c(n, vector<ll>(n)); // 2차원사이즈선언,1차원사이즈갯수선언
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
			c[i][j] %= 1000;
		}
	}
	return c;
}
int main() {
	scanf("%lld%lld", &n, &k);
	matrix a(n, vector<ll>(n));
	matrix ans(n, vector<ll>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf(" %lld", &a[i][j]);
			if (i == j) ans[i][j] = 1;
		}
	}

	while (k > 0) {
		if (k % 2 == 1) {
			ans = ans * a;
		}
		a = a * a;
		k /= 2;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%lld ", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}