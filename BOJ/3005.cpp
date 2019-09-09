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
int gox[4] = { -1,0,0,1 };
int goy[4] = { 0,1,-1,0 };
int n, m;
char board[21][21];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %c", &board[i][j]);
		}
	}
	vector<string> v;
	for (int i = 0; i < n; i++) {
		string s;
		for (int j = 0; j < m; j++) {
			if (board[i][j] == '#') {
				if (s.size() <= 1) s.clear();
				else {
					v.push_back(s);
					s.clear();
				}
			}
			else {
				s.push_back(board[i][j]);
			}
		}
		if (s.size() >= 2) {
			v.push_back(s);
		}
	}
	for (int j = 0;j < m; j++) {
		string s;
		for (int i = 0; i < n; i++) {
			if (board[i][j] == '#') {
				if (s.size() <= 1) s.clear();
				else {
					v.push_back(s);
					s.clear();
				}
			}
			else {
				s.push_back(board[i][j]);
			}
		}
		if (s.size() >= 2) {
			v.push_back(s);
		}
	}
	sort(v.begin(), v.end());
	printf("%s\n", v[0].c_str());
	return 0;
}