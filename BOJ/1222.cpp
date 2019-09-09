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
int t, Case = 1, n;
int arr[200000];
ll cnt[2000001];
void go(int num) {
	for (int i = 1; i <= sqrt(num); i++) {
		if (num%i == 0) {
			int p = i, q = num / i;
			cnt[p]++;
			if (p == q) continue;
			else {
				cnt[q]++;
			}
		}
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		go(arr[i]);
	}
	ll ans = 0;
	for (int i = 1; i <= 2000000; i++) {
		if (cnt[i] >= 2) {
			ans = max(ans, i*cnt[i]);
		}
	}
	printf("%lld\n", ans);
	return 0;
}