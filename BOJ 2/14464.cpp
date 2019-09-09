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
int c, n;
vector<int> v;
vector<P> v2;
bool compare(const P &a, const P &b) {
	if (a.second != b.second) return a.second < b.second;
	if (a.first != b.first) a.first < b.first;
}
int main() {
	scanf("%d%d", &c, &n);
	for (int i = 1; i <= c; i++) {
		int num;
		scanf("%d", &num);
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	for (int i = 1; i <= n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		v2.push_back({ x,y });
	}
	sort(v2.begin(), v2.end(), compare);
	int ptr = 0;
	int cnt = 0;
	for (int i = 0; i < v2.size(); i++) {
		vector<int>::iterator it = lower_bound(v.begin(), v.end(), v2[i].first);
		if (it == v.end()) continue;
		if (*it >= v2[i].first && *it <= v2[i].second) {
			cnt++;
			v.erase(it);
		}
	}
	printf("%d\n", cnt);
	return 0;
}