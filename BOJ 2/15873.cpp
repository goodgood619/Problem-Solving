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
typedef pair<double, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { -1,0,1,0 };
int goy[4] = { 0,1,0,-1 };
int t, Case = 1,n,m;
int main() {
	string s;
	cin >> s;
	if (s.size() == 2) {
		string s1, s2;
		s1.push_back(s[0]), s2.push_back(s[1]);
		printf("%d\n", stoi(s1) + stoi(s2));
	}
	else if (s.size() == 3) {
		if (s[0] == '1' && s[1] == '0') {
			string s1, s2;
			s1.push_back(s[0]), s1.push_back(s[1]), s2.push_back(s[2]);
			printf("%d\n", stoi(s1) + stoi(s2));
		}
		else {
			string s1, s2;
			s1.push_back(s[0]), s2.push_back(s[1]), s2.push_back(s[2]);
			printf("%d\n", stoi(s1) + stoi(s2));
		}
	}
	else {
		string s1, s2;
		s1.push_back(s[0]), s1.push_back(s[1]), s2.push_back(s[2]),s2.push_back(s[3]);
		printf("%d\n", stoi(s1) + stoi(s2));
	}
	return 0;
}