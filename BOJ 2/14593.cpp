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
typedef pair<int, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, Case = 1;
vector <PPPP> v;
typedef unsigned long long lll;
bool compare(const PPPP &a,const PPPP &b) {
	if (a.first.second != b.first.second) return a.first.second > b.first.second;
	if (a.second.first != b.second.first) return a.second.first < b.second.first;
	if (a.second.second != b.second.second) return a.second.second < b.second.second;
}
int main() {
	setbuf(stdout, NULL);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int s, c, l;
		scanf("%d%d%d", &s, &c, &l);
		v.push_back({ { i + 1,s }, { c,l } });
	}
	sort(v.begin(), v.end(), compare);
	printf("%d\n", v[0].first.first);
	return 0;
}