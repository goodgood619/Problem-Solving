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
int range[26][200001];
int main() {
	string s;
	cin >> s;
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < s.size(); j++) {
			char c = i + 'a';
			if (j >= 1) range[i][j] = range[i][j - 1];
			if (c == s[j]) {
				range[i][j]++;
			}
		}
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		char c;
		int p, q;
		scanf(" %c%d%d", &c, &p, &q);
		if(p>=1) printf("%d\n", range[c - 'a'][q] - range[c - 'a'][p-1]);
		else printf("%d\n", range[c - 'a'][q]);
	}
	return 0;
}