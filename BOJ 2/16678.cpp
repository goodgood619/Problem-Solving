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
typedef pair<ll, pair<ll, ll>> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
int n;
int main() {
	scanf("%d", &n);
	vector<int> v;
	ll sum = 0;
	int here = 0;
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		v.push_back(num);
	}
	sort(v.begin(),v.end());
	if (v[0] != 1) {
		sum += (v[0] - 1);
		v[0] = 1;
		here = 1;
	}
	else if (v[0] == 1) {
		here = 1;
	}
	for (int i = 1; i < v.size(); i++) {
		if (v[i] - here <= 1) {
			here = v[i];
		}
		else {
			sum += (v[i] - here - 1);
			v[i] = here + 1;
			here = v[i];
		}
	}
	printf("%lld\n", sum);
	return 0;
}