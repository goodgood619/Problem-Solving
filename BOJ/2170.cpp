#include <cstdio>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
P line[1000001];
int n;
ll sum;
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld%lld", &line[i].first, &line[i].second);
	}
	sort(line + 1, line + n + 1);
	sum = line[1].second - line[1].first;
	ll f = line[1].first;
	ll s = line[1].second;
	for (int i = 2; i <=n; i++) {
		ll first = line[i].first;
		ll second = line[i].second;
		if (f <= first && s <= second && first <= s) {
			sum += (second - s);
			s = second;
		}
		else if (first > s) {
			f = first;
			s = second;
			sum += (s - f);
		}
	}
	printf("%lld\n", sum);
	return 0;
}