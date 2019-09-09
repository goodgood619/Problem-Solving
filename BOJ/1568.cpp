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
using namespace std;
typedef long long ll;
#define INF 1000000000
typedef pair<int, int> P;
typedef pair<int, pair<int, int>> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
ll n;
int main() {
	scanf("%lld", &n);
	int ti = 0;
	while (1) {
		if (n == 0) break;
		for (ll i = 1;; i++) {
			if (n < i*(i + 1) / 2) {
				n -= (i * (i - 1) / 2);
				ti += i - 1;
				break;
			}
			else if (n == i * (i + 1) / 2) {
				ti += i;
				n -= (i * (i + 1) / 2);
				break;
			}
		}
	}
	printf("%d\n", ti);
	return 0;
}