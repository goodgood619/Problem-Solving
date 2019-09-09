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
typedef pair<int, int> P;
typedef pair<pair<int, int>, pair<int,int>> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
using namespace std;
string s1, s2;
int lcs[4005][4005];
int main() {
	cin >> s1 >> s2;
	if (s1[0] == s2[0]) lcs[0][0] = 1;
	for(int i=1;i<s1.size();i++) {
		if (s2[0] == s1[i]) {
			lcs[i][0] = 1;
		}
		else lcs[i][0] = max(lcs[i][0], lcs[i-1][0]);
	}
	for (int i = 1; i < s2.size(); i++) {
		if (s2[i] == s1[0]) lcs[0][i] = 1;
		else lcs[0][i] = max(lcs[0][i], lcs[0][i - 1]);
	}
	int Max = 0;
	for (int i = 1; i < s1.size(); i++) {
		for (int j = 1; j < s2.size(); j++) {
			if (s1[i] == s2[j]) lcs[i][j] = max(lcs[i - 1][j - 1] + 1, lcs[i][j]);
			Max = max(Max,lcs[i][j]);
		}
	}

	printf("%d\n", Max);
	return 0;
}