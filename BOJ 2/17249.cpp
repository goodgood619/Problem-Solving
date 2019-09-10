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
int t, Case = 1;
typedef unsigned long long lll;
int main() {
	setbuf(stdout, NULL);
	string s;
    cin>>s;
	int left = 0, right = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') left = i;
		else if (s[i] == ')') right = i;

	}
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < left; i++) {
		if (s[i] == '@') cnt1++;
	}
	for (int i = right; i <s.size(); i++) {
		if (s[i] == '@') cnt2++;
	}
	printf("%d %d\n", cnt1, cnt2);
	return 0;
}