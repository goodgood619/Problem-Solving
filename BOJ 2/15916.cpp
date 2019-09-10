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
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n;
ll k;
int main() {
	scanf("%d", &n);
	vector<ll> v;
	v.push_back(0);
	for (int i = 1; i <= n; i++) {
		ll num;
		scanf("%lld", &num);
		v.push_back(num);
	}
	scanf("%lld", &k);
	ll x = 1, y = v[1], kx = 1, ky = k;
	int up = 0, down = 0;
	if (v[1] > ky) {
		up = 1;
	}
	else if(v[1]<ky){
		down = 1;
	}
	else {
		printf("T\n");
		return 0;
	}
	for (int i = 2; i <= n; i++) {
		 x = i, y = v[i];
		 kx = i, ky = i*k;
		 if (y == ky) {
			 printf("T\n");
			 return 0;
		 }
		 else if (y < ky) {
			 if (up == 1) {
				 printf("T\n");
				 return 0;
			 }
		 }
		 else if (y > ky) {
			 if (down == 1) {
				 printf("T\n");
				 return 0;
			 }
		 }
	}
	printf("F\n");
	return 0;
}