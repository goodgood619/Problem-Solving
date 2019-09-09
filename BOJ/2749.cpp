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
ll n;
typedef vector<vector<ll>> matrix;
matrix operator * (const matrix &a, const matrix &b) {
	int n = a.size();
	matrix c(n, vector<ll>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
			c[i][j] %= 1000000;
		}
	}
	return c;
}
int main() {
	scanf("%lld", &n);
	if (n == 0 || n == 1) {
		printf("%lld\n", n);
		return 0;
	}
	n -= 1;
	matrix a = { { 1,1 },{ 1,0 } };
	matrix ans = { { 1,0 },{ 0,1 } };
	while (n > 0) {
		if (n % 2 == 1) {
			ans = ans * a;
		}
		a = a * a;
		n /= 2;
	}
	printf("%lld\n", ans[0][0]*1+ans[0][1]*0);
	return 0;
}