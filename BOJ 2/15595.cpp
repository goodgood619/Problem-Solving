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
typedef pair<ll, ll> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n;
map<string, int> wrong; //틀린사람
map<string, int> check; //진짜 맞은사람
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int num, ok, one, two, three, four;
		char s[25] = { '\0', };
		scanf("%d%s%d%d%d%d%d", &num, s, &ok, &one, &two, &three, &four);
		if (ok == 4 && !strcmp(s, "megalusion")) { //맞았는데 관리자
			continue;
		}
		else if (ok == 4 && strcmp(s, "megalusion")) { //맞았는데 관리자가 아님
			string st = s;
			if (check.count(st) == 0) {
				check[st] = 1;
			}
		}
		else { // 나머지경우 -> 틀림
			string st = s;
			if (check.count(st) != 0) { //이미 맞음
				continue;
			}
			wrong[st]++;
		}
	}
	int ctcnt = check.size();
	if (ctcnt == 0) {
		printf("%.9lf\n", 0);
	}
	else {
		map<string, int>::iterator it;
		int wrongsum = 0;
		for (it = check.begin(); it != check.end(); it++) {
			string name = it->first;
			wrongsum += wrong[name];
		}
		double d = (double)ctcnt / (double)(ctcnt + wrongsum) * 100;
		printf("%.9lf\n", d);
	}
	return 0;
}