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
#define mod 1000000009
#define lim 1000000000
typedef pair < ll, ll > P;
typedef pair<pair<int, int>, int> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n;
stack<P> st;
ll height[1000005];
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &height[i]);
	}
	ll ans = 0;
	st.push({ 0,0 });
	for (int i = 1; i <= n + 1; i++) {
		ll here = height[i];
		while (!st.empty() && st.top().first > here) { // 높이가 낮아지는 순간부터, 계속 pop을하면서 위치를 계산한다
			ll h = st.top().first;
			st.pop();
			ans = max(ans, h*(i - 1-st.top().second));  // 현재높이h그리고 i-1하면 현재위치가 된다, st.top().second는 pop을 했기 때문에 무조건 현재 전위치가 된다
		}
		st.push({ here,i });
	}
	printf("%lld\n", ans);
	return 0;
}