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
int t, Case = 1, n, m, r;
vector<ll> v,sell2;
vector<pair<ll, ll>> hab2,habsell1;
vector<pair<pair<ll, ll>, ll>> sell1;
ll habsell2[100002];
ll hab[100002];
bool compare1(const pair<pair<ll,ll>,ll> &a,const pair<pair<ll,ll>,ll> &b) {
	if (a.first.second != b.first.second) return a.first.second > b.first.second;
	if (a.first.first != b.first.first) return a.first.first > b.first.first;
	if (a.second != b.second) return a.second < b.second;
}
int main() {
	scanf("%d%d%d", &n, &m, &r);
	for (int i = 1; i <= n; i++) {
		ll num;
		scanf("%lld", &num);
		v.push_back(num);
	}
	sort(v.begin(), v.end(), greater<ll>());
	for (int i = 0; i < v.size(); i++) {
		hab[i + 1] += (hab[i] + v[i]);
	}

	for (int i = 1; i <= m; i++) {
		ll cnt, gallon;
		scanf("%lld%lld", &cnt, &gallon);
		sell1.push_back({{ cnt,gallon }, i});
	}
	sort(sell1.begin(), sell1.end(),compare1);
	ll cnt1 = 0, cnt2 = 0, sellhab = 0;
	for (int i = 0; i < sell1.size(); i++) {
		cnt2 = sell1[i].first.second;
		cnt1 += sell1[i].first.first;
		sellhab += (sell1[i].first.first*cnt2);
		habsell1.push_back({ cnt1,i });
		hab2.push_back({ cnt2,sellhab });
	}

	for (int i = 1; i <= r; i++) {
		ll num;
		scanf("%lld", &num);
		sell2.push_back(num);
	}
	sort(sell2.begin(), sell2.end(),greater<ll>());
	for (int i = 0; i < sell2.size(); i++) {
		habsell2[i + 1] += (habsell2[i] + sell2[i]);
	}

	ll Max = 0;
	for (int i = 0; i <= n; i++) {
		ll temp=0;
		temp += habsell2[i]; //r쪽
		int rest = n - i;
		if (rest < 0) continue;
		ll restmilk = hab[rest];
		vector<pair<ll,ll>>::iterator it = lower_bound(habsell1.begin(), habsell1.end(),pair<ll,ll>(restmilk,i));
		if (it == habsell1.end()) {
			it--;
			ll cnt = it->first;
			int index = it->second;
			ll cnt2 = hab2[it->second].first;
			ll resthab = hab2[it->second].second;
			if (restmilk == cnt) {
				temp += resthab;
			}
			else if (restmilk < cnt) {
				if (it == habsell1.begin()) {
					temp += restmilk * cnt2;
				}
				else {
					it--;
					temp += hab2[it->second].second;
					temp += (restmilk-(it->first))*cnt2;
				}
			}
			else {
				temp += resthab;
			}
		}
		else {
			ll cnt = it->first;
			int index = it->second;
			ll cnt2 = hab2[it->second].first;
			ll resthab = hab2[it->second].second;
			if (restmilk == cnt) {
				temp += resthab;
			}
			else if (restmilk < cnt) {
				if (it == habsell1.begin()) {
					temp += restmilk * cnt2;
				}
				else {
					it--;
					temp += hab2[it->second].second;
					temp+=(restmilk-(it->first))*cnt2;
				}
			}
			else {

			}
		}
		Max = max(Max, temp);
	}
	printf("%lld\n", Max);
	return 0;
}