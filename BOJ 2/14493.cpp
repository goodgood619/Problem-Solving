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
typedef pair<int,int> P;
typedef pair<ll, pair<ll,ll>> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
int n;
int main() {
	scanf("%d", &n);
	ll second = -1;
	for (int i = 1; i <= n; i++) {
		second++;
		int rest, attack;
		if (i == 1) {
			scanf("%d%d", &rest, &attack);
			second += (ll)attack;
			continue;
		}
		else {
			scanf("%d%d", &rest, &attack);
			int p = second;
			int mok = p / (rest + attack);
			p -= (ll)(mok*(rest + attack));
			if(attack>=p) second += (ll)(attack - p);
		}
	}
	printf("%lld\n", second+1);
	return 0;
}