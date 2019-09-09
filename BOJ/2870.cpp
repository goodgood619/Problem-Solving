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
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
vector<int> a;	
bool visited[55];
int n;
bool compare(const string &a, const string &b) {
	if (a.size() != b.size()) return a.size() < b.size();
	return a < b;
}
int main() {
	scanf("%d", &n);
	vector<string> v;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		string temp;
		int cnt = 0;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] >= '0' && s[j] <= '9') {
				temp.push_back(s[j]);
			}
			else {
				if (!temp.empty()) {
					int cnt2 = 0;
					for (int k = 0; k < temp.size(); k++) {
						if (temp[k] == '0') cnt2++;
					}
					if (cnt2 == temp.size()) v.push_back("0");
					else v.push_back(temp);
					temp.clear();

				}
			}
		}
		if (!temp.empty()) {
			int cnt2 = 0;
			for (int k = 0; k < temp.size(); k++) {
				if (temp[k] == '0') cnt2++;
			}
			if (cnt2 == temp.size()) v.push_back("0");
			else v.push_back(temp);
			temp.clear();

		}
	}

	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		string here = v[i];
		int idx = 0;
		if (here.size() > 1) {
			for (int j = 0; j < here.size(); j++) {
				if (here[j] != '0') {
					idx = j;
					break;
				}
			}
			if (idx > 0) {
				for(int j=0;j<idx;j++)
				v[i].erase(v[i].begin());
			}
		}
	}
	sort(v.begin(), v.end(),compare);
	for (int i = 0; i < v.size(); i++) {
		printf("%s\n", v[i].c_str());
	}
	return 0;
}