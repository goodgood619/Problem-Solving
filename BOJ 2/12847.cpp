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
using namespace std;
typedef long long ll;
int n, m;
ll arr[100005];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) { scanf("%lld", &arr[i]);}
	int right = 1;
	int cnt = 0;
	ll sum = 0;
	ll ans = 0;
	int first = 1;
	if (m == 0) printf("0\n");
	else {
		while (1) {
			if (right > n) break;
			if (cnt < m) {
				sum += arr[right];
				cnt++;
				right++;
			}
			else if (cnt == m) {
				ans = max(ans, sum);
				cnt--;
				sum -= arr[first];
				first++;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}