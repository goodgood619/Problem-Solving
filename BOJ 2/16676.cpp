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
typedef pair<pair<int, int>, int> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
ll n;
int main() {
	scanf("%lld", &n);
	if (n <= 10) {
		printf("1\n");
		return 0;
	}
	ll sum = 10;
	int Set = 1;
	vector<pair<pair<ll, ll>, int>> v;
	for (; sum <= n;) {
		ll p = sum;
		p += 1;
		string temp = to_string(p);
		temp.push_back('0');
		ll q = stoll(temp);
		sum = q;
		Set++;
		v.push_back({ {p,q }, Set });
	}
	int ans = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].first.first <= n && n <= v[i].first.second) {
			ans = v[i].second;
			break;
		}
	}
	printf("%d\n", ans);

	return 0;
}