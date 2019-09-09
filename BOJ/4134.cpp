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
int isprime[1000005];
vector<int> v;
int main() {
	for (int i = 2; i <= 70000; i++) isprime[i] = i;
	for (int i = 2; i <= sqrt(70000); i++) {
		if (isprime[i] == 0) continue;
		for (int j = i * i; j <= 70000; j += i) {
			isprime[j] = 0;
		}
	}
	// n이 소수인지 판별을 하려면, n의 양의 제곱근보다 작은 소수로 나누어 떨어지지 않는다면 그것은 소수
	int t;
	scanf("%d", &t);
	while (t--) {
		ll n;
		scanf("%lld", &n);
		if (n <= 1) {
			printf("2\n");
			continue;
		}

		for (ll i = n;; i++) {
			int no = 0;
			ll m = sqrt(i);
			for (ll j = 2; j <= m; j++) {
				if (isprime[j] == 0) continue;
				else {
					if (i%j == 0) {
						no = 1;
						break;
					}
				}
			}
			if (!no) {
				printf("%lld\n", i);
				break;
			}
		}
	}
	return 0;
}