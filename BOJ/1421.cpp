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
#define mod 1000000009
#define lim 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = {0,1,-1,0};
int goy[4] = {1,0,0,-1};
int n, c, w;
vector<int> v;
int main(void) {
	scanf("%d%d%d", &n, &c, &w);
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	ll Max = -1e9;
	int Maxheight = v[v.size() - 1];
	for (ll i = Maxheight; i >=1; i--) {
		ll temp = 0;
		for (int j = 0; j <v.size(); j++) {
			if (i > v[j]) continue;
			int restwood = v[j] / i;
			int cut = (v[j]-1)/i;
			if (i*w*restwood - cut * c > 0) temp += (i*w*restwood - cut * c); //이익이 발생할때만 더해라
		}
		Max = max(Max, temp);
	}
	printf("%lld\n", Max);
	return 0;
}