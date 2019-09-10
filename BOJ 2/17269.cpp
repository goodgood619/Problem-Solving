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
int t, Case = 1,n,m;
map<char, int> mm;
int main() {
	setbuf(stdout, NULL);
	scanf("%d%d", &n, &m);
	string s1, s2;
	cin >> s1 >> s2;
	int check = 0;
	string s;
	mm['A'] = 3, mm['B'] = 2, mm['C'] = 1, mm['D'] = 2, mm['E'] = 4, mm['F'] = 3, mm['G'] = 1, mm['H'] = 3, mm['I'] = 1, mm['J'] = 1, mm['K'] = 3, mm['L'] = 1, mm['M'] = 3, mm['N'] = 2, mm['O'] = 1, mm['P'] = 2, mm['Q'] = 2;
	mm['R'] = 2, mm['S'] = 1, mm['T'] = 2, mm['U'] = 1, mm['V'] = 1, mm['W'] = 1, mm['X'] = 2, mm['Y'] = 2, mm['Z'] = 1;
	for (int i = 0, j = 0; i < s1.size() || j < s2.size();) {
		if (check == 0) {
			if (i < s1.size()) {
				s.push_back(s1[i]);
				i++;
				check = 1;
			}
			else check = 1;
		}
		else {
			if (j < s2.size()) {
				s.push_back(s2[j]);
				j++;
				check = 0;
			}
			else check = 0;
		}
	}
	vector<int> v;
	for (int i = 0; i < s.size(); i++) {
		v.push_back(mm[s[i]]);
	}

	while (1) {
		if (v.size() == 2) break;
		vector<int> temp;
		for (int i = 0; i < v.size() - 1; i++) {
			int sum = v[i] + v[i + 1];
			if (sum > 10) sum %= 10;
			temp.push_back(sum);
		}
		v = temp;
	}
	string ans;
	v[0] %= 10, v[1] %= 10;
	char c1 = v[0] + '0', c2 = v[1] + '0';
	if (c1 == '0') ans.push_back(c2);
	else ans.push_back(c1), ans.push_back(c2);
	cout << ans<<'%';
	return 0;
}