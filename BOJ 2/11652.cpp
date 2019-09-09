#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
map <ll, ll> m;
int main(){
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		ll num;
		scanf("%lld", &num);
		m[num]++;
	}
	map<ll, ll> ::iterator it;
	ll ans = 0;
	ll what = 0;
	for (it = m.begin(); it!=m.end(); it++) {
		ll cnt = it->second;
		if (ans < cnt) {
			ans = cnt;
			what = it->first;
		}
	}
	printf("%lld\n",what);
	return 0;
}