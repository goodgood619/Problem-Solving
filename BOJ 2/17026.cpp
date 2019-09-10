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
	for (int i = 1; i <= n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		v.push_back({ x - y,x + y });
	}
	sort(v.begin(), v.end());
	int cnt = 1;
	int left = v[0].first, right = v[0].second;
	for (int i = 1; i < v.size(); i++) {
		int nleft = v[i].first, nright = v[i].second;
		if (right < nright && left<nleft && right>nleft || right<=nleft) {
			left = nleft, right = nright;
			cnt++;
		}
		left = min(left, nleft);
		right = max(right, nright);
	}
	printf("%d\n", cnt);
	return 0;
}