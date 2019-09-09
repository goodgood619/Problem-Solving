
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
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n;
int main() {
	while (~scanf("%d ", &n)) {
		string s = "1";
		for (int i = 0;; i++) {
			int ret = 0;
			for (int i = 0; i < s.size(); i++) {
				ret = (ret * 10 + (s[i] - '0')) % n;
			}
			if (ret == 0) break;
			s.append("1");
		}
		printf("%d\n", s.size());
	}
	return 0;
}