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
typedef pair<int, pair<int, int>> PP;
typedef pair<pair<string, int>, pair<int, int>> PPP;
int w, n;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
vector<int> v;
vector<P> l, r;
map<vector<int>, int> m;
int go(int value, vector<PP> l) {
	int left = 0;
	int right = l.size();
	while (left <= right) {
		int mid = (left + right) / 2;
		if (l[mid].first<value) left = mid + 1;
		else right = mid - 1;
	}
	return left;
}

int main() {
	scanf("%d%d", &w, &n);
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		l.push_back({ v[i],i });
	}

	vector<PP> l2;
	vector<int> l3;
	for (int i = 0; i < l.size(); i++) {
		int heresum = l[i].first;
		int here = l[i].second;
		for (int j = i + 1; j < l.size(); j++) {
			vector<int> temp;
			int nextsum = l[j].first;
			int next = l[j].second;
			temp.push_back(here);
			temp.push_back(next);
			l2.push_back({ heresum + nextsum,{ here,next } });
			
		}
	}

	sort(l2.begin(), l2.end());
	for (int i = 0; i < l2.size(); i++) {
		l3.push_back(l2[i].first);
	}
	bool ok = false;
	for (int i = 0; i < l3.size(); i++) {
		auto it = lower_bound(l3.begin(), l3.end(), w - l3[i]);
		auto it2 = upper_bound(l3.begin(), l3.end(), w - l3[i]);
		if (*it + l3[i] == w && it2 != l3.end()) {
			int a = l2[i].second.first;
			int b = l2[i].second.second;
			int idx1 = it - l3.begin();
			int idx2 = it2 - l3.begin();
			for (; idx1< idx2; idx1++) {
				int aa = l2[idx1].second.first;
				int bb = l2[idx1].second.second;
				if (a == aa || a == bb || b == aa || b == bb) continue;
				else {
					ok = true;
					break;
				}
			}
			if (ok) break;
		}
	}
	if (ok) printf("YES\n");
	else printf("NO\n");

	return 0;
}