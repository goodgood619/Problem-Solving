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
int t, Case = 1, n,m;
ll gas[100001], dist[100001];
int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++)  scanf("%lld", &dist[i]);
	for (int i = 1; i <= n; i++) scanf("%lld", &gas[i]);
	ll sum = dist[1] * gas[1];
	ll Mingas = gas[1];
	for (int i = 2; i < n; i++) {
		if (Mingas > gas[i]) {
			sum += dist[i] * gas[i];
			Mingas = gas[i];
		}
		else sum += dist[i] * Mingas;
	}
	printf("%lld\n", sum);
	return 0;
}