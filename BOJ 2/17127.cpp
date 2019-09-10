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
int gox[4] = { -1,0,0,1 };
int goy[4] = { 0,1,-1,0 };
int n;
vector<ll> v;
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		ll num;
		scanf("%lld", &num);
		v.push_back(num);
	}
	ll temp1 = 1, temp2 = 1, temp3 = 1, temp4 = 1;
	ll ans = -1e14;
	for (int i = 0; i < v.size(); i++) {
		temp1 *= v[i];
		temp2 = 1;
		for (int j = i + 1; j < v.size(); j++) {
			temp2 *= v[j];
			temp3 = 1;
			for (int k = j + 1; k < v.size(); k++) {
				temp3 *= v[k];
				temp4 = 1;
				for (int p = k + 1; p < v.size(); p++) {
					temp4 *= v[p];
					ans = max(ans, temp1 + temp2 + temp3 + temp4);
				}
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}