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
#define mod 1000000009
#define lim 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = {0,1,-1,0};
int goy[4] = {1,0,0,-1};
ll st, en;
map<ll, int> visited;
string bfs(ll here) {
	queue<pair<ll, string>> q;
	q.push({ here,"" });
	visited[here] = 1;
	vector<string> v;
	while (!q.empty()) {
		ll s = q.front().first;
		string ss = q.front().second;
		q.pop();
		if (s == en) {
			v.push_back(ss);
		}
		ll s1 = s + s;
		ll s2 = s - s;
		ll s3 = s * s;
		ll s4 = 0;
		if (s != 0) s4 = s/s;
		// 순서가 매우매우 중요!!
		if (visited.count(s3) == 0 ) {
			visited[s3] = 1;
			q.push({ s3,ss + "*" });
		}
		if (visited.count(s1) == 0 ) {
			visited[s1] = 1;
			q.push({s1,ss + "+" });
		}
		if (visited.count(s2) == 0 ) {
			visited[s2] = 1;
			q.push({ s2,ss + "-" });
		}
		if (visited.count(s4) == 0 && s4==1) {
			visited[s4] = 1;
			q.push({ s4,ss + "/" });
		}
	}
	if (v.size() == 0) {
		printf("-1\n");
		exit(0);
	}
	else return v[0];
}
int main(void) {
	scanf("%lld%lld", &st, &en);
	if (st == en) printf("0\n");
	else printf("%s\n",bfs(st).c_str());
	return 0;
}