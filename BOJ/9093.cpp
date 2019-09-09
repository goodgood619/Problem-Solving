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
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0, -1,0,1 };
int goy[4] = { 1, 0,-1,0 };
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		char c[1005] = { '\0', };
		scanf(" %[^\n]s", c);
		string s;
		s = c;
		int first = 0;
		vector<string> v;
		string t;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ' ') {
				first = 1;
				reverse(t.begin(), t.end());
				v.push_back(t);
				t.clear();
			}
			else {
				t.push_back(s[i]);
			}
		}
		reverse(t.begin(), t.end());
		v.push_back(t);
		for (int i = 0; i < v.size(); i++) {
			if (i == v.size() - 1) printf("%s\n", v[i].c_str());
			else printf("%s ", v[i].c_str());

		}
	}
	return 0;
}