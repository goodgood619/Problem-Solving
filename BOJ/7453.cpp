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
typedef pair<int, int> P;
typedef pair<pair<int, int>, pair<int, int>> PP;
typedef pair<double, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
using namespace std;
int n;
int arr[4001][5];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 4; j++) {
			scanf(" %d", &arr[i][j]);
		}
	}
	vector<int> v1, v2;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int k = 1, p = 2;
			v1.push_back(arr[i][k] + arr[j][p]);
			v2.push_back(arr[i][k + 2] + arr[j][p + 2]);
		}
	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	vector<int>::iterator it,it2;
	ll cnt = 0;
	for (int i = 0; i < v1.size(); i++) {
		it = lower_bound(v2.begin(), v2.end(), -v1[i]);
		it2 = upper_bound(v2.begin(), v2.end(), -v1[i]);
		cnt += (it2 - it);
	}
	printf("%lld\n", cnt);
	return 0;
}