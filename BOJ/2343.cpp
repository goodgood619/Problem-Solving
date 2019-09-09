
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
typedef pair<int,int> P;
typedef pair<pair<int, int>,int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n, m;
int arr[100005];
int main() {
	scanf("%d%d", &n, &m);
	int Max = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		Max = max(Max, arr[i]);
	}
	ll left =(ll)Max; // 주의 1번
	ll right = 1e14;
	while (left <= right) {
		ll mid = (left + right) / 2;
		int sum = 0;
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (sum + arr[i] > mid) {
				sum = 0;
				cnt++;
			}
			sum += arr[i];
		}
		if (sum > 0) cnt++;
		if (cnt <=m) right = mid - 1;
		else left = mid + 1;
	}
	printf("%lld\n", left);
	return 0;
}