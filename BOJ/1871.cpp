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
	scanf("%d", &t);
	while (t--) {
		string s,s1,s2;
		cin >> s;
		for (int i = 0; i < 3; i++) s1.push_back(s[i]);
		for (int i = 4; i < 8; i++) s2.push_back(s[i]);
		int a = 0;
		for (int i = 0; i < s1.size(); i++) {
			a += (s1[i] - 'A')*pow(26, s1.size() - i - 1);
		}
		abs(stoi(s2) - a) <= 100 ? printf("nice\n") : printf("not nice\n");
	}
	return 0;
}