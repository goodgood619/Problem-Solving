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
int t, Case = 1, n, m;
int ball[101];
int main() {
	scanf("%d", &t);
	while (t--) {
		int idx;
		string s;
		cin >> idx >> s;
		for (int i = 0; i < s.size(); i++) {
			if (idx - 1 == i) continue;
			else printf("%c", s[i]);
		}
		printf("\n");
	}
	return 0;
}