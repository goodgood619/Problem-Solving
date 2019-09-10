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
int t, Case = 1;
map<char, int> m;
int main() {
	string s;
	cin >> s;
	bool palindrome = true;
	for (int i = 0, j = s.size() - 1; i <= j; i++, j--) {
		if (s[i] != s[j]) {
			palindrome = false;
			break;
		}
	}
	if (!palindrome) printf("%d\n", s.size());
	else {
		for (int i = 0; i < s.size(); i++) {
			m[s[i]]++;
		}
		if (m.size() == 1) printf("-1\n");
		else printf("%d\n", s.size() - 1);
	}
	return 0;
}