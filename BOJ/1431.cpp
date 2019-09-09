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
typedef pair<pair<int, int>,string> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
int rx[8] = { 0,0,1,-1,1,1,-1,-1 };
int ry[8] = { 1,-1,0,0,1,-1,1,-1 };
int n;
string original[1005];
bool compare(const PP &a, const PP &b) {
	if (a.first.first != b.first.first) return a.first.first < b.first.first;
	if (a.first.second != b.first.second) return a.first.second < b.first.second;
	if (a.second != b.second) return a.second < b.second;
}
int main() {
	scanf("%d", &n);
	vector<PP> v;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		original[i] = s;
	}
	for (int i = 1; i <= n; i++) {
		int Size = original[i].size();
		int sum = 0;
		for (int j = 0; j < original[i].size(); j++) {
			char c = original[i][j];
			if (c >= '0' && c <= '9') sum +=(c-'0');
		}
		v.push_back({ {Size,sum},original[i] });
	}

	sort(v.begin(), v.end(), compare);
	for (int i = 0; i < v.size(); i++) {
		printf("%s\n", v[i].second.c_str());
	}
	return 0;
}