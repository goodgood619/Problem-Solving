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
typedef pair<int, int> P;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = {0,1,-1,0};
int goy[4] = {1,0,0,-1};
int t;
int main(void) {
	scanf("%d", &t);
	while (t--) {
		ll n;
		scanf("%lld", &n);
		ll sum = 0;
		for (int i = 0; i < n; i++) {
			ll num;
			scanf("%lld", &num);
			sum += num;
			sum %= n;
		}
		sum%n == 0 ? printf("YES\n") : printf("NO\n");
	}
	return 0;
}