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
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t, Case = 1, n,d;

int main() {
	setbuf(stdout, NULL);
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string s;
	cin >>n>> s;
	ll c = 0, o = 0, w = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'C') c++;
		else if (s[i] == 'O') o += c;
		else if (s[i] == 'W') w += o;
	}
	printf("%lld\n", w);
	return 0;
}
