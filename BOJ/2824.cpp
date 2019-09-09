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
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n, m;
ll arr[1005];
ll arr2[1005];
ll gcd(ll a, ll b) {
	if (a%b == 0) return b;
	else return gcd(b%a, a);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf(" %lld", &arr[i]);
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		scanf(" %lld", &arr2[i]);
	}
	ll Max = 1;
	bool over = false;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ll g = gcd(arr[i], arr2[j]);
			arr[i] /= g;
			arr2[j] /= g;
			Max *= g;
			if (Max > 1e9) {
				Max %= (ll)1e9;
				over = true;
			}
		}
	}
	if (!over) {
		printf("%lld\n", Max);
	}
	else {
		Max %= (ll)1e9;
		ll p = Max;
		int cnt = 0;
		while (p > 0) {
			p /= 10;
			cnt++;
		}
		for(int i=9-cnt;i>=1;i--){
			printf("0");
		}
		printf("%lld\n", Max);
	}
	return 0;
}