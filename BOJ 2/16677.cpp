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
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
int n;
string s[105];
bool num[105];
int total[105];
bool visited[105][105];
string word;
bool compare(const pair<double, int> &a, const pair<double,int> &b) {
	if (a.first != b.first) return a.first > b.first;
	if (a.second != b.second) return a.second < b.second;
}
int main() {
	cin >> word;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		cin >> total[i];
	}
	for (int i = 0; i < n; i++) {
		string here = s[i];
		int idx = 0;
		for (int j = 0; j < here.size(); j++) {
			if (word[idx] == here[j]) {
				visited[i][j] = true;
				idx++;
			}
			else continue;
		}
		if (idx == word.size()) {
			num[i] = true;
		}
	}
	vector<pair<double,int>> ans;
	for (int i = 0; i < n; i++) {
		if (num[i] == false) continue;
		int cnt = 0;
		for (int j = 0; j < s[i].size(); j++) {
			if (!visited[i][j]) cnt++;
		}
		ans.push_back({ (double)(total[i])/cnt,i});
	}
	sort(ans.begin(), ans.end(), compare);
	if (ans.size() == 0) printf("No Jam\n");
	else printf("%s\n", s[ans[0].second].c_str());
	return 0;
}