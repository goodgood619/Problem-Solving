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
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, Case = 1;
typedef unsigned long long lll;
int main() {
	setbuf(stdout, NULL);
	while (1) {
		string s;
		int a, b;
		cin >> s >> a >> b;
		if (s[0] == '#' && a == 0 && b == 0) break;
		a > 17 || b >= 80 ? printf("%s Senior\n", s.c_str()) : printf("%s Junior\n", s.c_str());
	}
	return 0;
}