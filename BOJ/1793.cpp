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
using namespace std;
typedef long long ll;
#define INF 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n;
string dp[280];
string go(string s1, string s2) {
	string temp;
	int sum = 0;
	while (!s1.empty() || !s2.empty() || sum!=0) {
		if (!s1.empty()) {
			sum += (s1.back() - '0');
			s1.pop_back();
		}
		if (!s2.empty()) {
			sum += (s2.back() - '0');
			s2.pop_back();
		}
		temp.push_back(sum % 10 + '0');
		sum /= 10;
	}
	reverse(temp.begin(), temp.end());
	return temp;
}
int main() {
	dp[0] = "1";
	dp[1] = "1";
	dp[2] = "3";
	for (int i = 3; i <= 250; i++) {
		dp[i] = go(go(dp[i - 2],dp[i - 2]),dp[i-1]);
	}


	while (scanf("%d", &n) != EOF) {
		printf("%s\n", dp[n].c_str());
	}
	return 0;
}