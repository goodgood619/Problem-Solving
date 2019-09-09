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
int n;
int main() {
	int Case = 1;
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		vector<string> v;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			v.push_back(s);
		}
		vector<string> ans;
		vector<string> ans2;
		for (int i = 0; i < v.size(); i++) {
			ans.push_back(v[i]);
			i++;
			if (i == v.size()) break;
			ans2.push_back(v[i]);
		}
		reverse(ans2.begin(), ans2.end());
		printf("SET %d\n", Case++);
		for (int i = 0; i < ans.size(); i++) {
			printf("%s\n", ans[i].c_str());
		}
		for (int i = 0; i < ans2.size(); i++) {
			printf("%s\n", ans2[i].c_str());
		}
	}
	return 0;
}