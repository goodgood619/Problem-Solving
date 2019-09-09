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
typedef pair<ll, ll> P;
priority_queue<ll, vector<ll>> pq;
P dia[300005];
ll bag[300005];
int n, m;
int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		ll a, b;
		scanf("%lld%lld", &a, &b);
		dia[i].first = a;
		dia[i].second = b;
	}
	sort(dia + 1, dia + n + 1);
	for (int i = 1; i <= m; i++) {
		scanf("%lld", &bag[i]);
	}
	sort(bag + 1, bag + m + 1);
	pq.push(0);
	ll sum = 0;
	for (int i = 1,j=1; i <= m; i++){
		ll diaweight=dia[j].first;
		ll bagweight = bag[i];
		while (j <= n && bagweight>=dia[j].first) pq.push(dia[j++].second);
		if (!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}
	}
	printf("%lld\n", sum);
	return 0;
}