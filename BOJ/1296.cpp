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
int n;
string s[55];
string oh;
int ohcnt[27];
int cnt[50][27];
bool compare(const pair<int, string> &a, const pair<int, string> &b) {
	if (a.first != b.first) return a.first > b.first;
	if (a.second != b.second) return a.second < b.second;
}
int main() {
	cin >> oh;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < oh.size(); i++) {
		ohcnt[oh[i] - 'A']++;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < s[i].size(); j++) {
			cnt[i][s[i][j] - 'A']++;
		}
	}
	vector<pair<int,string>> ans;
	// abcdefghijklmnopqrstuvwxyz
	// e:4,l:11, o:14,v:21
	// l:11,o:14,v:21,e:4
	int Max = -1;
	int idx = 0;
	for (int i = 0; i < n; i++) {
		int l = ohcnt[11], o = ohcnt[14], v = ohcnt[21], e = ohcnt[4];
		int gl = cnt[i][11], go = cnt[i][14], gv = cnt[i][21], ge = cnt[i][4];
		int arr[4] = { 0, };
		arr[0] = max(arr[0],l+gl), arr[1] = max(arr[1],o+go), arr[2] = max(arr[2],v+gv), arr[3] = max(arr[3],e+ge);
		vector<int> vv;
		for (int i = 0; i < 4; i++) {
			for (int j = i + 1; j < 4; j++) {
				vv.push_back(arr[i] + arr[j]);
			}
		}
		int M = (vv[0] * vv[1] * vv[2] * vv[3] * vv[4] * vv[5]) % 100;
		ans.push_back({ M,s[i] });
	}

	sort(ans.begin(), ans.end(), compare);
	printf("%s\n", ans[0].second.c_str());
	return 0;
}