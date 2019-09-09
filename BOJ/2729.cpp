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
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		string s1, s2;
		cin >> s1 >> s2;
		if (s1.size() < s2.size()) swap(s1, s2);
		int rest = s1.size() - s2.size();
		string t;
		int check = 0;
		int n = -1;
		for (int i = s1.size() - 1; i >= 0; i--) {
			if (i - rest >= 0) n = (s1[i] - '0') + (s2[i - rest] - '0') + (check == 1 ? 1 : 0);
			else n = (s1[i] - '0') + (check == 1 ? 1 : 0);
			if (n < 2) {
				t.push_back(n + '0');
				check = 0;
			}
			else {
				check = 1;
				if (n == 3) t.push_back('1');
				else t.push_back('0');
			}
		}
		if (check == 1) t.push_back('1');
		reverse(t.begin(), t.end());
		int idx = -1;
		for (int i = 0; i < t.size(); i++) {
			if (t[i] == '1') {
				idx = i;
				break;
			}
		}
		if (idx == -1) {
			printf("0\n");
			continue;
		}
		for (int i = idx; i < t.size(); i++) {
			printf("%c", t[i]);
		}
		printf("\n");
	}
	return 0;
}