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
typedef pair<pair<int, int>, pair<int, bool>> PPP;
int gox[4] = {0,1,-1,0};
int goy[4] = {1,0,0,-1};
int n;
ll sum = 0;
ll gcd(ll a, ll b) {
	if (a%b == 0) return b;
	else return gcd(b%a, a);
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		sum = 0;
		vector<ll> v;
		for (int i = 0; i < n; i++) {
			ll num;
			scanf("%lld", &num);
			v.push_back(num);
		}
		for (int i = 0; i < v.size(); i++) {
			for (int j = i+1; j <v.size(); j++) {
				sum += gcd(v[i], v[j]);
			}
		}
		printf("%lld\n", sum);
	}
	return 0;
}