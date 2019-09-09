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
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = {-1,1,0,0 };
int goy[4] = {0,0,-1,1 };
int n, k;
int main() {
	scanf("%d%d", &n, &k);
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	int left = 0, right = 1;
	ll Min = 1e10;
	while (left <= right) {
		if (right == v.size()) break;
		if (v[right] - v[left] >= k) {
			if (left == right) {
				right++;
				continue;
			}
			Min = min(Min, (ll)v[right] - v[left]);
			left++;
		}
		else {
			right++;
		}
	}
	printf("%lld\n", Min);
	return 0;
}