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
//#define mod 1000000007
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = {-1,1,0,0 };
int goy[4] = {0,0,-1,1 };
ll n, k;
int main() {
	while (~scanf("%lld%lld", &n, &k)) {
		ll sum = n;
		while (1) {
			ll mok = n / k;
			ll mod = n % k;
			sum += mok;
			n = mok + mod;
			if (n < k) break;
		}
		printf("%lld\n", sum);
	}
	return 0;
}