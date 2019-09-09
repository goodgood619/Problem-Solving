#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <map>
#include <set>
#include <list>
#include <climits>
#include <deque>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
ll board[105][105];
string dp[105][105];
int n;
string bigadd(string s1, string s2){
	ll sum = 0;
	string temp;
	while (!s1.empty() || !s2.empty() || sum){
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
string go(ll x, ll y) {
	if (x > n || y > n || x <= 0 || y <= 0) return "0";
	if (x == n && y == n) return "1";
	string &ret = dp[x][y];
	if (ret != "") return ret;
	ll jump = board[x][y];
	if (jump == 0) return ret;
	ret = bigadd(go(x + jump, y), go(x, y + jump));
	return ret;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %lld", &board[i][j]);
		}
	}
	cout << go(1, 1) << endl;
	return 0;
}