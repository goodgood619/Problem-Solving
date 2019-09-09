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
typedef pair<double, double> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
typedef pair<pair<double, double>, pair<double, double>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n, s;
map<int, int, greater<int>> m;
int main() {
	scanf("%d", &n);
	vector<PP> v;
	for (int i = 0; i < n; i++) {
		int left, right, height;
		scanf("%d%d%d", &left, &right, &height);
		v.push_back({ { left,-1 }, height });
		v.push_back({ { right,1 }, height });
	}
	sort(v.begin(), v.end());
	int pre = 0;
	ll total = 0;
	for (int i = 0; i < v.size(); i++) {
		if (m.size() == 0) {
			pre = v[i].first.first;
			m[v[i].second]++;
		}
		else {
			if (v[i].first.second == -1) { //새로운시작
				total += (ll)(v[i].first.first - pre)*(ll)(m.begin()->first);
				m[v[i].second]++;
				pre = v[i].first.first;
			}
			else { //끝
				total += (ll)(v[i].first.first - pre)*(ll)(m.begin()->first);
				m[v[i].second]--;
				if (m[v[i].second] == 0) {
					m.erase(m.find(v[i].second));
				}
				pre = v[i].first.first;
			}
		}
	}
	printf("%lld\n", total);
	return 0;
}