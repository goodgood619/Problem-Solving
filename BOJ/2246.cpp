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
int gox[4] = { -1,0,0,1 };
int goy[4] = { 0,1,-1,0 };
int n;
vector<P> v;
P condo[10005];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int dist, cost;
		scanf("%d%d", &dist, &cost);
		v.push_back({ dist,cost });
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for (int i = v.size()-1; i>=0; i--) {
		int dist1 = v[i].first, cost1 = v[i].second;
		int no = 0, same = 0;
		for (int j = i -1; j >=0; j--) {
			int dist2 = v[j].first, cost2 = v[j].second;
			if (cost1 >= cost2) {
				no = 1;
				break;
			}
		}
		if (!no) condo[i].first = 1;
	}
	
	for (int i = 0; i < v.size(); i++) {
		int dist1 = v[i].first, cost1 = v[i].second;
		int no = 0,same=0;
		for (int j = i + 1; j < v.size(); j++) {
			int dist2 = v[j].first, cost2 = v[j].second;
			if (cost1 >= cost2) {
				if (dist1 < dist2) continue;
				no = 1;
				break;
			}
		}
		if (!no) condo[i].second = 1;
	}
	for (int i = 0; i < v.size(); i++) {
		if (condo[i].first && condo[i].second) ans++;
	}
	printf("%d\n", ans);
	return 0;
}