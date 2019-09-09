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
int gox[4] = {-1,1,0,0 };
int goy[4] = {0,0,-1,1 };
string a, b;
vector<vector<char>> num;
int main() {
	cin >> a >> b;
	if (a.size() != b.size()) {
		printf("0\n");
	}
	else {
		int cnt = 0;
		for (int i = 0; i < a.size(); i++) {
			if (a[i] == '8' && a[i] == b[i]) cnt++;
			else if (a[i] == b[i]) continue;
			else if (a[i] != b[i]) break;
		}
		printf("%d\n", cnt);
	}
	return 0;
}