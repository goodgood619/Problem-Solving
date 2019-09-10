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
ll sum, c, k, p;
int main() {
	scanf("%lld%lld%lld", &c, &k, &p);
	ll cnt = 1;
	while (cnt <= c) {
		sum += (cnt*k) + (cnt*cnt*p);
		cnt++;
	}
	printf("%lld\n", sum);
	return 0;
}