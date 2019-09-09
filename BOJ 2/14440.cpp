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
ll x,y,n;
string zero, one;
typedef vector<vector<ll>> matrix;
matrix operator * (const matrix &a, const matrix &b) {
	int n = a.size();
	matrix c(n, vector<ll>(n)); // 2차원사이즈선언,1차원사이즈갯수선언
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
			c[i][j] %= 100;
		}
	}
	return c;
}
int main() {
	scanf("%lld%lld", &x,&y);
	cin >> zero >> one;
	scanf("%lld", &n);
	if (n == 0) {
		printf("%s\n",zero.c_str());
		return 0;
	}
	if (n == 1) {
		printf("%s\n", one.c_str());
		return 0;
	}

	matrix a = { {x,y},{1,0} };
	matrix ans = { {1,0 },{ 0,1 } };
	while (n > 0) {
		if (n % 2 == 1) {
			ans = ans * a;
		}
		a = a * a;
		n /= 2;
	}
	ll c=(ans[1][0]*stoll(one)+ans[1][1]*stoll(zero))%100;
	c >= 10 ? printf("%lld\n", c) : printf("0%lld\n", c);
	return 0;
}