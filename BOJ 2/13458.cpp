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
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0};
int goy[4] = { 1,0,0,-1};
int n,b,c;
int arr[1000005];
int main() {
	scanf("%d", &n);
	ll cnt = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	scanf("%d%d", &b, &c);
	for (int i = 1; i <= n; i++) {
		if (b > arr[i]) {
			cnt++;
			continue;
		}
		else {
			arr[i] -= b;
			cnt++;
			int mok = arr[i] / c;
			int MOD = arr[i] % c;
			cnt += (ll)mok;
			if (MOD != 0) cnt += 1;
		}
	}
	printf("%lld\n", cnt);
	return 0;
}