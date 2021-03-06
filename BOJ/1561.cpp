
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
#define mod 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
ll n, m;
ll toy[10005];
int main() {
	scanf("%lld%lld", &n,&m);
	for (int i = 1; i <= m; i++) {
		scanf("%lld", &toy[i]);
	}
	ll left = 1;
	ll right = 1e14;
	if (n <= m) { //애초에 놀이기구 갯수가 더많으면, 그냥 n번째는 n번째꺼타면됨
		printf("%lld\n", n);
		return 0;
	}
	while (left <= right) {
		ll mid = (left + right) / 2;
		ll cnt = m;
		for (int i = 1; i <= m; i++) {
			cnt += (mid / toy[i]);
		}
		if (cnt < n) left = mid + 1;
		else right = mid - 1;
	}
	left--;
	ll sum = m; // 맨처음에 시작할때는 m개를 채우고 시작하기때문
	for (int i = 1; i <= m; i++) {
		sum += (left / toy[i]);
	}
	left++;
	for (int i = 1; i <= m; i++) {
		if (left%toy[i] == 0) sum++;
		if (sum == n) {
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}

