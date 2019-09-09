#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <math.h>
#include <iostream>
#include <string>
#include <stack>
#include <string.h>
#include <map>
using namespace std;
int ans,q;
stack<int> temp;
typedef long long ll;
typedef pair<ll, int> PP;
ll n,k;
int main(){
	scanf("%lld%lld%d", &n, &k, &q);
	if (k== 1){
		for (int i = 1; i <= q; i++) {
			ll a, b;
			scanf("%lld%lld", &a, &b);
			printf("%lld\n", abs(a - b));
		}
		return 0;
	}
	for (int i = 1; i <= q; i++){
		map<ll, int> m;
		ll a, b;
		int cnt = 0;
		scanf("%lld%lld", &a, &b);
		while (a !=0) {
			m[a] = cnt;
			if (a == 1) break;
			a = (a - 2) / k + 1;
			cnt++;
		}
		cnt = 0;
		while (b !=0){
			if (m.count(b) != 0) {
				printf("%d\n",m[b]+cnt);
				break;
			}
			m[b] = cnt;
			if (b == 1) break;
			b = (b - 2) / k + 1;
			cnt++;
		}

	}
	return 0;
}
