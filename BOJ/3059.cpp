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
int t, Case = 1, n, m;
map<int, int> checkx,checky;
int main() {
	scanf("%d", &t);
	while (t--) {
		string s;
		cin >> s;
		int check[26] = { 0, };
		for (int i = 0; i < s.size(); i++) {
			check[s[i] - 'A'] = 1;
		}
		int sum = 0;
		for (int i = 0; i < 26; i++) {
			if (check[i] == 0) sum += (i + 65);
		}
		printf("%d\n", sum);
	}
	return 0;
}