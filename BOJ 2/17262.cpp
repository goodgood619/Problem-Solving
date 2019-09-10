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
typedef pair<double, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<double, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, Case = 1,n;
int main() {
	setbuf(stdout, NULL);
	scanf("%d", &n);
	vector<pair<int, int>> v;
	int Min=1e9;
	for (int i = 0; i < n; i++) {
		int si, ei;
		scanf("%d%d", &si, &ei);
		v.push_back({ si,ei });
		Min = min(Min, ei);
	}
	sort(v.begin(), v.end());
	int ans = 1e9;
	for (int i = 1; i <= Min; i++) {
		if (i <= v[v.size() - 1].first) {
			ans = min(ans, v[v.size() - 1].first - i);
		}
	}
	printf("%d\n", ans);
	return 0;
}