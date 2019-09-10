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
typedef pair<char, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, Case = 1;
string s;
int ans;
int arr[10];
bool visited[10];
map<vector<string>,int> m;
vector<string> vv;
typedef unsigned long long lll;
void go(int left,int right,string ss,int cnt) {
	if (cnt == s.size()) {
		if (m.count(vv) == 0) {
			ans++;
			m[vv] = 1;
		}
		return;
	}	
	if (left >= 1 && !visited[left-1]) {
		visited[left - 1] = true;
		string ttt;
		ttt.push_back(arr[left-1]+'0');
		for (int i = 0; i < ss.size(); i++) ttt.push_back(ss[i]);
		vv.push_back(ttt);
		go(left - 1, right,ttt , cnt + 1);
		vv.pop_back();
		visited[left - 1] = false;
	}
	if (right < s.size() - 1 && !visited[right+1]) {
		visited[right + 1] = true;
		string tt = ss;
		tt.push_back(arr[right + 1] + '0');
		vv.push_back(tt);
		go(left, right + 1, tt, cnt + 1);
		vv.pop_back();
		visited[right + 1] = false;
	}
}
int main() {
	setbuf(stdout, NULL);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		arr[i] = s[i] - '0';
	}
	for (int i = 0; i < s.size(); i++) {
			vv.clear();
			string tt = to_string(arr[i]);
			vv.push_back(tt);
			visited[i] = true;
			go(i,i,tt,1);
			visited[i] = false;
	}
	printf("%d\n", ans);
	return 0;
}