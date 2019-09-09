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
typedef pair<double, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { -1,0,1,0 };
int goy[4] = { 0,1,0,-1 };
int t, Case = 1, n, m;
int main() {
	for (int i = 0; i < 3; i++) {
		int a, b, c, d, e, f;
		scanf(" %d%d%d%d%d%d", &a, &b, &c, &e, &d, &f);
		while (true) {
			if (f >= c) f -= c;
			else f += 60, f -= c,d-=1;
			if (d >= b) d -= b;
			else d += 60, d -= b, e -= 1;
			e -= a;
			break;
		}
		printf("%d %d %d\n", e, d, f);
	}
	return 0;
}