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
typedef pair<int, int> P;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = {0,1,-1,0};
int goy[4] = {1,0,0,-1};
int t;
int main(void) {
	scanf("%d", &t);
	while (t--) {
		ll n;
		scanf("%lld", &n);
		vector<ll> v;
		for (int i = 1; i <= 6; i++) {
			ll num;
			scanf("%lld", &num);
			v.push_back(num);
		}
		int cnt = 1;
		// 0:1,3,5 1:0,2,4 2:1,3,5
		while (1) {
			vector<ll> temp;
			ll p = n;
			for (int i = 0; i < v.size(); i++) {
				p -= v[i];
			}
			if (p < 0) break;
			for (int i = 0; i < v.size(); i++) {
				if (i % 2 == 0) {
					temp.push_back(v[i] + v[1] + v[3] + v[5]);
				}
				else {
					temp.push_back(v[i] + v[0] + v[2] + v[4]);
				}
			}
			v=temp;
			cnt++;
		}
		printf("%d\n", cnt);
	}
	return 0;
}