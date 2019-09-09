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
int gox[4] = { 0, 0,1,-1 };
int goy[4] = { 0, 1,1,1 };
int failure[1000005];
int t;
int main() {
	while (1) {
		string s;
		cin >> s;
		if (s.size() == 1 && s[0] == '.') break;
		memset(failure, 0, sizeof(failure));
		int j = 0;
		int n = s.size();
		for (int i = 1; i < s.size(); i++) {
			while (j > 0 && s[i] != s[j]) j = failure[j - 1];
			if (s[i] == s[j]) {
				failure[i] = j + 1;
				j++;
			}
		}
		if (failure[n - 1] == 0 || n %(n-failure[n-1])!=0) {
			printf("%d\n", 1);
			continue;
		}
		else printf("%d\n", n / (n -failure[n-1]));
	}
	return 0;
}