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
typedef pair<int, ll> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
string up, down;
int main() {
	getline(cin, up);
	getline(cin, down);
	int ans = 0;
	for (int i = 0; i < up.size();) {
		int no = 0;
		int st = i;
		for (int j = 0; j < down.size(); j++) {
			if (up[st] == down[j]) {
				st++;
				continue;
			}
			else {
				if (st == up.size()) {
					no = 1;
					break;
				}
				no = 1;
				break;
			}
		}
		if (!no) {
			i = i + down.size();
			ans++;
		}
		else i++;
	}
	printf("%d\n", ans);
	return 0;
}