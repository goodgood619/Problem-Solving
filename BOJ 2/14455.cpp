#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <string>
#include <iostream>
using namespace std;
int n;
typedef pair<string, int> P;
P cnt[10005];
map<string, int> m;
map<int, int> samem;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		int milk;
		cin >> milk;
		if (n == 1) {
			printf("%s\n", s.c_str());
			return 0;
		}
		if (m.count(s) == 0) {
			m[s] = milk;
		}
		else m[s] += milk;
	}
	map<string, int>::iterator it;
	map<string, int>::iterator it2;
	int Min = 99999999;
	int same = 0;
	for (it = m.begin(); it != m.end(); it++) {
		int smallmilk = it->second;
		if (Min > smallmilk) {
			Min = smallmilk;
		}
		else if (Min == smallmilk) {
			same++;
		}
	}
	if (same == n - 1) {
		printf("Tie\n");
		return 0;
	}
	if (m.size() < 7) {
		printf("Tie\n");
		return 0;
	}
	bool check = false;
	for (it2 = m.begin(); it2 != m.end(); it2++) {
		int smallmilk = it2->second;
		if (smallmilk > Min) {
			cnt[smallmilk].first = it2->first;
			cnt[smallmilk].second++;
		}
		else continue;
	}
	for (int i = 1; i <= 10000; i++) {
		if (i <= Min) continue;
		else if (cnt[i].second == 0) continue;
		else if (cnt[i].second == 1) {
			printf("%s", cnt[i].first.c_str());
			return 0;
		}
		else {
			printf("tie\n");
			return 0;
		}
	}
	return 0;
}