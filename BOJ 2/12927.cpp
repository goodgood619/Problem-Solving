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
int t, Case = 1, n, m;
int main() {
	setbuf(stdout, NULL);
	string s;
	cin >> s;
	int cnt = 0, no = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'N') continue;
		else {
			int temp = i + 1;
			for (int j = i; j < s.size(); j += temp) {
				s[j] == 'Y' ? s[j] = 'N' : s[j] = 'Y';
			}
			cnt++;
		}
	}
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'N') no++;
	}
	no != s.size() ? printf("-1\n") : printf("%d\n", cnt);
	return 0;
}