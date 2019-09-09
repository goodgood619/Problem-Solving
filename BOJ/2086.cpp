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
#define mod 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
typedef vector<vector<ll>> matrix;
ll a, b;
matrix operator *(const matrix &a, const matrix &b) {
	matrix c(2, vector<ll>(2));
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
			c[i][j] %= mod;
		}
	}
	return c;
}
int main() {
	scanf("%lld%lld", &a, &b);
	b += 2, a += 1;
	matrix p1(2, vector<ll>(2));
	matrix p2(2, vector<ll>(2));
	matrix ans1(2, vector<ll>(2));
	matrix ans2(2, vector<ll>(2));
	ans1 = { { 1,0 }, { 0,1 } };
	ans2 = { {1,0},{0,1} };
	p1 = { {1,1},{1,0} };
	p2 = { {1,1},{1,0} };
	while (a > 0) {
		if (a % 2 == 1) {
			ans1 = ans1 * p1;
		}
		p1 = p1 * p1;
		a /= 2;
	}
	while (b > 0) {
		if (b % 2 == 1) {
			ans2 = ans2 * p2;
		}
		p2 = p2 * p2;
		b /= 2;
	}
	ll A =ans1[0][1];
	ll B = ans2[0][1];
	B=((B% mod- A%mod)+mod)%mod;
	printf("%lld\n", B % 1000000000);
	return 0;
}