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
#define mod 1000000009
typedef pair<int, int> P;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = {0,1,-1,0};
int goy[4] = {1,0,0,-1};
string s;
ll k;
int main(void) {
	cin >> s >> k;
	int no = 0;
	for (int i = 0, j = s.size() - 1;i<=j; i++, j--) {
		if (s[i] == s[j]) continue;
		else {
			no = 1;
			break;
		}
	}
	no == 1 ? printf("NO\n") : printf("YES\n");
	return 0;
}