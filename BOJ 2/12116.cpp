#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <functional>
#include <map>
#include <iostream>
#include <string>
#include <deque>
#include <stack>
#include <math.h>
using namespace std;
typedef long long ll;
ll sum[150005];
#define L 1e10
typedef pair<ll, ll> P;
vector<P> ans;
ll n;
int main(){
	scanf("%lld", &n);
	ll Max = sqrt(2 * n) + 1;
	for (ll i = 2; i <= Max; i++) {
		ll y = n - i*(i + 1) / 2;
		if (y < 0) continue;
		if (y%i == 0) {
			printf("%lld %lld\n", y / i + 1,(y / i + i));
		}
	}
	return 0;
}