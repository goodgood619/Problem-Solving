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
typedef pair<double, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { -1,0,1,0 };
int goy[4] = { 0,1,0,-1 };
int t, Case = 1;
int main() {
	string a, b;
	cin >> a >> b;
	sort(a.begin(), a.end());
	int ans = -1;
	do {
		int numa = stoi(a);
		int numb = stoi(b);
		if (numa <= numb && a[0]!='0') {
			ans = max(ans,numa);
		}
	} while (next_permutation(a.begin(), a.end()));
	printf("%d\n", ans);
	return 0;
}