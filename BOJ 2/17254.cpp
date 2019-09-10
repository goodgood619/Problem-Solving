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
typedef pair<pair<int, int>, int> PP;
typedef pair<char, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, Case = 1, n, m;
typedef unsigned long long lll;
bool compare(const PPP &a, const PPP &b) {
	if (a.second.second != b.second.second) return a.second.second < b.second.second;
	if (a.second.first != b.second.first) return a.second.first < b.second.first;
}
int main() {
	setbuf(stdout, NULL);
	scanf(" %d%d", &n, &m);
	vector<PPP> v;
	for (int i = 1; i <= m; i++) {
		int a, b;
		char c;
		scanf("%d%d %c", &a, &b, &c);
		v.push_back({ c,{a,b} });
	}
	sort(v.begin(), v.end(), compare);
	string s;
	for (int i = 0; i < v.size(); i++) {
		s.push_back(v[i].first);
	}
	printf("%s\n", s.c_str());
	return 0;
}