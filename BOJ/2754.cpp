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
int gox[4] = { 0, -1,0,1 };
int goy[4] = { 1, 0,-1,0 };
int main() {
	map<string, double> m;
	m["A+"] = 4.3, m["A0"] = 4.0, m["A-"] = 3.7, m["B+"] = 3.3, m["B0"] = 3.0, m["B-"] = 2.7, m["C+"] = 2.3, m["C0"] = 2.0, m["C-"] = 1.7, m["D+"] = 1.3, m["D0"] = 1.0, m["D-"] = 0.7,m["F"]=0.0;
	string s;
	cin >> s;
	printf("%.1lf\n", m[s]);
	return 0;
}