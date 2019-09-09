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
#define mod 1000000009
typedef pair<int, int> P;
typedef pair<pair<ll, ll>, ll> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,1, -1,0 };
int goy[4] = { 1,0, 0,-1 };
int n, k, b;
queue<int> q;
int broke[100005];
int main() {
	scanf("%d%d%d", &n, &k, &b);
	for (int i = 1; i <= b; i++) {
		int num;
		scanf("%d", &num);
		broke[num]++;
	}
	int cnt = 0,ptr=1;
	int ans = 1e9;
	for (int i = 1; i <= n; i++) {

		if (broke[i]) {
			q.push(i);
			cnt++;
			if (cnt >= k) {
				int temp = q.size();
				ans = min(ans, temp);
				cnt--;
				if (!q.empty() && q.front()==ptr) q.pop();
				ptr++;
			}
		}
		else {
			cnt++;
			if (cnt >= k) {
				int temp = q.size();
				ans = min(ans, temp);
				cnt--;
				if (!q.empty() && q.front()==ptr) q.pop();
				ptr++;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}