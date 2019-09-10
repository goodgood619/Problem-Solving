#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
typedef long long ll;
priority_queue<ll, vector<ll>, greater<ll>> pq;
int n,m;
int main(){
	scanf("%d%d", &n,&m);
	for (int i = 1; i <= n; i++) {
		ll num;
		scanf("%lld", &num);
		pq.push(num);
	}
	for (int i = 1; i <= m; i++) {
		ll num1 = pq.top();
		pq.pop();
		ll num2 = pq.top();
		pq.pop();
		ll num3 = num1 + num2;
		pq.push(num3);
		pq.push(num3);
	}
	ll total = 0;
	while (!pq.empty()) {
		ll num = pq.top();
		total += num;
		pq.pop();
	}
	printf("%lld\n", total);
	return 0;
}