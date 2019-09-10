
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
typedef pair<int, ll> P;
typedef pair<int, pair<ll,char>> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
typedef pair<ll, ll> p;
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
int n;
bool visited[123460];
string s[123460];
ll cnt[123460];
vector<vector<int>> a;
ll dfs(int here) {
	visited[here] = true;
	ll ret = 0;
	for (int i = 0; i < a[here].size(); i++) {
		int next = a[here][i];
		if (!visited[next]) {
			ret += dfs(next);
		}
	}
	if (s[here] == "S") {
		ret += cnt[here];
	}
	else {
		if (ret < cnt[here]) ret = 0;
		else ret -=cnt[here];
	}
	return ret;
}
int main() {
	scanf("%d", &n);
	a.resize(n + 1);
	for (int i = 2; i <= n; i++) {
		char c;
		ll num;
		int pre;
		scanf(" %c %lld %d", &c, &num, &pre);
		a[pre].push_back(i);
		s[i] = c;
		cnt[i] = num;
	}
	ll sum = dfs(1);
	printf("%lld\n", sum);
	return 0;
}
