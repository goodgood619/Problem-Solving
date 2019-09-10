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
typedef pair<double, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n;
vector<int> v;
int cnt[55];
int main() {
	scanf(" %d", &n);
	for (int i = 0; i < n; i++) {
		int num;
		scanf(" %d", &num);
		cnt[num]++;
	}
	char s[100003] = { '\0', };
	scanf(" %[^\n]s", s);
	int length = strlen(s);
	int no = 0;
	for (int i = 0; i < length; i++) {
		char c = s[i];
		if (c == ' ') {
			if (cnt[0] == 0) {
				no = 1;
				break;
			}
		}
		else if (c >= 'A' && c <= 'Z') {
			cnt[c - 64]--;
			if (cnt[c - 64] < 0) {
				no = 1;
				break;
			}
		}
		else {
			cnt[c  - 70]--;
			if (cnt[c- 70] < 0) {
				no = 1;
				break;
			}
		}
	}
	no == 1 ? printf("n") : printf("y");
	return 0;
}