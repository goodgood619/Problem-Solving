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
typedef pair<double, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<double, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, Case = 1,n;
int main() {
	setbuf(stdout, NULL);
	string s;
	cin >> s;
	int no = 0,diff=1e9;
	for (int i = 1; i < s.size(); i++) {
		if (diff == 1e9) {
			diff = (s[i] - '0') - (s[i - 1] - '0');
		}
		else {
			if (diff != (s[i] - '0') - (s[i - 1] - '0')) {
				no = 1;
				break;
			}
		}
	}
	no ? printf("흥칫뿡!! <(￣ ﹌ ￣)>") : printf("◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!");
	return 0;
}