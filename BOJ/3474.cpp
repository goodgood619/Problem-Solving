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
typedef pair<ll, pair<ll, ll>> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
int t;
int main() {
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int sum2 = 0, sum5 = 0;
		for (int i = 2; i <= n; i *= 2) {
			sum2 += (n / i);
		}
		for (int i = 5; i <= n; i *= 5) {
			sum5 += (n / i);
		}
		printf("%d\n", min(sum2, sum5));
	}
	return 0;
}