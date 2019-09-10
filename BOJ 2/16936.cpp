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
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n;
map<ll, int> m;
ll arr[105];
vector<ll> v;
void dfs(ll here,int cnt) {
	if (m.count(here) == 0) return;
	if (cnt == n) {
		for (int i = 0; i < v.size(); i++) {
			printf("%lld ", v[i]);
		}
		exit(0);
	}

	if (here % 3 == 0) {
		v.push_back(here / 3);
		dfs(here / 3, cnt + 1);
		v.pop_back();
	}
	v.push_back(here * 2);
	dfs(here * 2, cnt + 1);
	v.pop_back();
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &arr[i]);
		m[arr[i]] = 1;
	}
	for (int i = 1; i <= n; i++) {
		v.push_back(arr[i]);
		dfs(arr[i], 1);
		v.pop_back();
	}
	return 0;
}