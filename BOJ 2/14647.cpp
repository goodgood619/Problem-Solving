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
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n, m;
int board[505][505];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf(" %d", &board[i][j]);
		}
	}
	int Max = 0, idx = -1;
	for (int i = 1; i <= n; i++) {
		int temp = 0;
		for (int j = 1; j <= m; j++) {
			string s = to_string(board[i][j]);
			for (int k = 0; k < s.size(); k++) {
				if (s[k] == '9') temp++;
			}
		}
		if (Max < temp) {
			Max = temp;
			idx = i;
		}
	}
	int idy = -1;
	for (int j = 1; j <= m; j++) {
		int temp = 0;
		for (int i = 1; i <= n; i++) {
			string s = to_string(board[i][j]);
			for (int k = 0; k < s.size(); k++) {
				if (s[k] == '9') temp++;
			}
		}
		if (Max < temp) {
			Max = temp;
			idy = j;
		}
	}

	if (idy == -1) {
		int total = 0;
		for (int i = 1; i <= n; i++) {
			int temp = 0;
			if (i == idx) continue;
			for (int j = 1; j <= m; j++) {
				string s = to_string(board[i][j]);
				for (int k = 0; k < s.size(); k++) {
					if (s[k] == '9') temp++;
				}
			}
			total += temp;
		}
		printf("%d\n", total);
	}
	else {
		int total = 0;
		for (int j = 1; j <= m; j++) {
			int temp = 0;
			if (idy == j) continue;
			for (int i = 1; i <= n; i++) {
				string s = to_string(board[i][j]);
				for (int k = 0; k < s.size(); k++) {
					if (s[k] == '9') temp++;
				}
			}
			total += temp;
		}
		printf("%d\n", total);
	}
	return 0;
}