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
typedef pair<double, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<double, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { -1,0,1,0 };
int goy[4] = { 0,1,0,-1 };
int goz[2] = { 1,-1 };
int t, Case = 1;

int main() {
	ll n;
	scanf("%lld", &n);
	ll k = 2;
	for (int i = 2; i <= 64; i++) {
		k *= 2;
		ll sum = (k - 1)*i + i - 1;
		if (sum >= n) {
			printf("%d\n", i - 1);
			return 0; 
		}
	}
	return 0;
}