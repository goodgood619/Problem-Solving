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
typedef pair<int,int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		ll n, a, b;
		scanf("%lld%lld%lld", &n, &a, &b);
		n = pow(2, n);
		int cnt = 0;
		while (1) {
			if (a == 0 && b == 0) {
				break;
			}
			ll p = n / 2;
			ll q = n / 2;
			int ok1 = 0, ok2 = 0;
			if (a >= p) {
				a -= p;
				ok1 = 1;
			}
			if (b >= p) {
				b -= p;
				ok2 = 1;
			}
			cnt++;
			if (ok1 || ok2) {
				n = n / 2;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}