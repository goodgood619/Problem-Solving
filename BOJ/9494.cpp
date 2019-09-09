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
typedef pair<int, pair<int, int>> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
typedef pair<ll, ll> p;
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
int n;
int main() {
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		string s[1005];
		for (int i = 0; i < n; i++) {
			char c[105] = { '\0', };
			scanf(" %[^\n]s", c);
			s[i] = c;
		}
		int start = 0;
		for (int i = 0; i < n; i++) {
			string pre;
			if (i > 0) {
				pre = s[i - 1];
			}
			string here = s[i];
			for (int j = start; j < here.size(); j++) {
				if (s[i][j] != ' ') {
					start++;
					continue;
				}
				else {
					start = j;
					break;
				}
			}
			
		}
		printf("%d\n", start + 1);
	}
	return 0;
}