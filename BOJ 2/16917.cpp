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
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
ll a, b, c, x, y;
int main() {
	scanf("%lld%lld%lld%lld%lld", &a, &b, &c, &x, &y);
	if (a + b <= 2 * c) { //그냥 따로사는게 이득
		printf("%lld\n", a*x + b * y);
	}
	else { //반반을 무조건 사는게 이득
		ll Min = min(x, y);
		ll sum = 0;
		sum += Min * 2 * c;
		x -= Min,y-=Min;
		if (x > 0) { //양념치킨이 남았거나
			ll rest1 = 2 * c*x; //반반치킨쪽으로 나머지를 살것인가
			ll rest2 = a * x; //그냥 따로 양념치킨을 시킬것인가
			sum += min(rest1, rest2);
		}
		if (y > 0) { //후라이드치킨이 남았거나
			ll rest1 = 2 * c*y;
			ll rest2 = b * y;
			sum += min(rest1, rest2);
		}
		printf("%lld\n", sum);
	}
	return 0;
}