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
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, Case = 1, n,d;
bool visited[1000001];
stack<pair<int,pair<int,char>>> st;
int main() {
	setbuf(stdout, NULL);
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string s,T;
	cin >> s>>T;
	int idx = 0;
	string r;
	for (int i = 0; i < s.size(); i++) {
		r += s[i];
		if (r.size() >= T.size() && r.substr(r.size() - T.size()) == T) {
			r.resize(r.size() - T.size());
		}
	}
	cout << r;
	return 0;
}
