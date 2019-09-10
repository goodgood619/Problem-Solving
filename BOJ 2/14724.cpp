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
int n;
string s[9] = { "PROBRAIN", "GROW", "ARGOS", "ADMIN", "ANT", "MOTION", "SPG", "COMON", "ALMIGHTY" };
int main() {
	scanf("%d", &n);
	int ans = 0;
	string temp;
	for (int i = 0; i < 9; i++) {
		int Max = 0;
		for (int j = 0; j < n; j++) {
			int num;
			scanf("%d", &num);
			Max = max(Max, num);
		}
		if (ans < Max) {
			ans = Max;
			temp = s[i];
		}
	}
	printf("%s\n", temp.c_str());
	return 0;
}