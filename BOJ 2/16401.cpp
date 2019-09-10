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
int n, m;
int arr[1000005];
int main() {
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	int left = 1;
	int right = 1e9 + 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		ll cnt = 0;
		for (int i = 1; i <= n; i++) {
			cnt +=(ll)(arr[i]) / mid;
		}
		if (cnt < m) right = mid - 1;
		else left = mid + 1;
	}
	printf("%d\n", left-1);
	return 0;

}
