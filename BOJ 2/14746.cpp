#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <functional>
#include <map>
#include <iostream>
#include <string>
#include <deque>
#include <stack>
#include <math.h>
using namespace std;
typedef long long ll;
vector<ll> p;
vector<ll> q;
int n, m;
ll py, qy;
map<ll, int> mm;
int main(){
	scanf("%d%d", &n,&m);
	scanf("%lld%lld", &py, &qy);
	for (int i = 1; i <= n; i++) {
		ll num;
		scanf("%lld", &num);
		p.push_back(num);
	}
	for (int i = 1; i <= m; i++) {
		ll num;
		scanf("%lld", &num);
		q.push_back(num);
	}
	sort(p.begin(), p.end());
	sort(q.begin(), q.end());
	int length = p.size();
	vector<ll>::iterator it;
	vector<ll>::iterator it2;
	ll Min = 9999999999;
	for (int i = 0; i < length; i++){
		ll here = p[i];
		it = lower_bound(q.begin(), q.end(), here);
		if (it == q.end())it--;
		if (it != q.begin()){
			it2 = it;
			it2--;
			ll dist = abs(here - *it) + abs(py - qy);
			Min = min(Min, dist);
			mm[dist]++;
			ll dist2 = abs(here - *it2) + abs(py - qy);
			Min = min(Min, dist2);
			mm[dist2]++;
		}
		else if (it == q.begin()){
			ll dist = abs(here - *it) + abs(py - qy);
			Min = min(Min, dist);
			mm[dist]++;
		}
	}
	printf("%lld %d\n", Min, mm[Min]);
	return 0;
}