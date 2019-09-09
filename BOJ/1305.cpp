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
int n;
string s;
int main() {
	scanf("%d", &n);
	cin >> s;
	int j = 0;
	int Max = 0;
	for (int i = 1; i < s.size(); i++) {
		while (j > 0 && s[i] != s[j]) j = failure[j - 1];
		if (s[i] == s[j]) {
			failure[i] = j + 1;
			Max = max(Max, failure[i]);
			j++;
		}
	}
	printf("%d\n", n - failure[n-1]);
	return 0;
}