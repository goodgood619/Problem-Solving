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
typedef pair<double, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { -1,0,1,0 };
int goy[4] = { 0,1,0,-1 };
int t, Case = 1, n,k,d;
int main() {
	scanf("%d%d%d", &n, &k, &d);
	vector<pair<pair<int, int>, int >> v;
	for (int i = 1; i <= k; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		v.push_back({ {a,b }, c });
	}
	int left = 0, right = n;
	int ans = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		ll sum = 0;
		for (int i = 0; i < v.size(); i++) {
			int last = min(v[i].first.second, mid);
			if (last >= v[i].first.first) {
				sum += ((last - v[i].first.first) / v[i].second);
				sum++;
			}
		}
		if (sum >= d) {
			right = mid - 1;
			ans = mid;
		}
		else {
			left = mid + 1;
		}
	}
	printf("%d\n", ans);
	return 0;
}