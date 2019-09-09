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
using namespace std;
typedef long long ll;
ll n;
ll maxx, maxy;
ll ans = 21000000000;
ll minx = 1000000000;
ll miny = 1000000000;
typedef pair<ll, ll> P;
vector<P> anspo;
void go(vector<P> temp,bool ok){
	int idx = 0;
	ll value1, value2;
	if (!ok) {
		for (int i = 0; i <n; i++) {
			if (maxx == temp[i].first) {
				value1 = temp[i].first;
				value2 = temp[i].second;
				temp.erase(temp.begin() + i);
				break;
			}
		}
		sort(temp.begin(), temp.end());
		ll a= 0;
		ll b = 0;
		ll c= 1000000000;
		ll d = 1000000000;
		for (int i = 0; i < n - 1; i++) {
			c = min(c, temp[i].first);
			d = min(d, temp[i].second);
			a= max(a, temp[i].first);
			b= max(b, temp[i].second);
		}
		ans = min(ans, (d-b)*(c-a));
	}
	else {
		for (int i = 0; i <n; i++) {
			if (maxy == temp[i].second) {
				temp.erase(temp.begin() + i);
				break;
			}
		}
		sort(temp.begin(), temp.end());
		ll a = 0;
		ll b = 0;
		ll c = 1000000000;
		ll d = 1000000000;
		for (int i = 0; i < n - 1; i++) {
			c = min(c, temp[i].first);
			d = min(d, temp[i].second);
			a = max(a, temp[i].first);
			b = max(b, temp[i].second);
		}
		ans = min(ans, (d - b)*(c - a));
	}
}
void go2(vector<P> temp, bool ok) {
	int idx = 0;
	ll value1, value2;
	if (!ok) {
		for (int i = 0; i <n; i++) {
			if (minx == temp[i].first) {
				value1 = temp[i].first;
				value2 = temp[i].second;
				temp.erase(temp.begin() + i);
				break;
			}
		}
		sort(temp.begin(), temp.end());
		ll a = 0;
		ll b = 0;
		ll c = 1000000000;
		ll d = 1000000000;
		for (int i = 0; i < n - 1; i++) {
			c = min(c, temp[i].first);
			d = min(d, temp[i].second);
			a = max(a, temp[i].first);
			b = max(b, temp[i].second);
		}
		ans = min(ans, (d - b)*(c - a));
	}
	else {
		for (int i = 0; i <n; i++) {
			if (miny == temp[i].second) {
				temp.erase(temp.begin() + i);
				break;
			}
		}
		sort(temp.begin(), temp.end());
		ll a = 0;
		ll b = 0;
		ll c = 1000000000;
		ll d = 1000000000;
		for (int i = 0; i < n - 1; i++) {
			c = min(c, temp[i].first);
			d = min(d, temp[i].second);
			a = max(a, temp[i].first);
			b = max(b, temp[i].second);
		}
		ans = min(ans, (d - b)*(c - a));
	}
}
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		ll num1, num2;
		scanf("%lld%lld", &num1, &num2);
		anspo.push_back({ num1,num2 });
	}
	sort(anspo.begin(),anspo.end());
	for (int i = 0; i < n; i++) {
		minx = min(minx, anspo[i].first);
		miny = min(miny, anspo[i].second);
		maxx = max(maxx, anspo[i].first);
		maxy = max(maxy, anspo[i].second);
	}
	vector<P> temp;
	temp = anspo;
	go(temp,false);
	temp = anspo;
	go(temp,true);
	temp = anspo;
	go2(temp, false);
	temp = anspo;
	go2(temp, true);
	printf("%lld\n", ans);
	return 0;
}