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
#define mod 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n;
ll arr[1000005];
int main() {
	scanf("%d", &n);
	arr[0] = 0;
	arr[1] = 1;
	int p = n;
	if (n < 0) n = -n;
	if (n == 0) {
		printf("0\n0\n");
		return 0;
	}

	for (int i = 2; i <= n; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2]) % mod;
	}
	if (p < 0 && abs(p) % 2 == 0) {
		printf("-1\n");
		printf("%lld\n", arr[n] % mod);
	}
	else if (p < 0 && abs(p) % 2 == 1) {
		printf("1\n");
		printf("%lld\n", arr[n] % mod);
	}
	else {
		printf("1\n");
		printf("%lld\n", arr[n] % mod);
	}
	return 0;
}
