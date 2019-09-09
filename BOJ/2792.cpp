#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
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
typedef pair<int, pair<int, int>> PP;
typedef pair<pair<string, int>, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
ll n, m;
ll child[300005];
priority_queue<P, vector<P>, greater<P>> pq;
int main(){
	scanf("%lld%lld", &n, &m);
	for (ll i = 1; i <= m; i++) {
		scanf("%lld", &child[i]);
	}
	ll left = 0;
	ll right = 1e14;
	while (left <= right) {
		ll mid = (left + right) / 2;
		ll cnt = 0;
		for (ll i = 1; i <= m; i++){
			if (child[i] % mid != 0){
				cnt += (child[i] / mid);
				cnt += 1;
			}
			else cnt += (child[i] / mid);
		}
		if (cnt <=n) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	printf("%lld\n", left);
	return 0;
}