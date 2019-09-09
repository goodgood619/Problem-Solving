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
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n, q, p;
vector<int> v;
bool compare(const int &a, const int &b) {
	if (a != b) return a > b;
}
int main() {
	scanf("%d%d%d", &n, &q, &p);
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		v.push_back(num);
	}
	if (n == p) {
		if (v[v.size() - 1] >= q) printf("-1\n");
		else {
			v.push_back(q);
			sort(v.begin(), v.end());
			reverse(v.begin(), v.end());
			vector<int> rank;
			int same = 0;
			int cur = v[0];
			int s = 1;
			rank.push_back(s);
			for (int i = 1; i < v.size(); i++) {
				int next = v[i];
				if (cur > next) {
					if (same > 0) {
						s += same;
					}
					cur = next;
					rank.push_back(++s);
					same = 0;
				}
				else {
					same++;
					rank.push_back(s);
				}
			}
			int idx = 0;
			for (int i = 0; i < v.size(); i++) {
				if (q == v[i]) {
					idx = i;
					break;
				}
			}
			if (idx >= p) printf("-1\n");
			else {
				printf("%d\n", rank[idx]);
			}
		}
	}
	else {
		v.push_back(q);
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		vector<int> rank;
		int same = 0;
		int cur = v[0];
		int s = 1;
		rank.push_back(s);
		for (int i = 1; i < v.size(); i++) {
			int next = v[i];
			if (cur > next) {
				if (same > 0) {
					s += same;
				}
				cur = next;
				rank.push_back(++s);
				same = 0;
			}
			else {
				same++;
				rank.push_back(s);
			}
		}
		int idx = 0;
		for (int i = 0; i < v.size(); i++) {
			if (q == v[i]) {
				idx = i;
				break;
			}
		}
		if (idx >= p) printf("-1\n");
		else {
			printf("%d\n", rank[idx]);
		}
	}
	return 0;
}