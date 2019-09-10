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
using namespace std;
typedef long long ll;
#define INF 1000000000
typedef pair<char,char> P;
typedef pair<int, pair<int, int>> PP;
typedef pair<double, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
char board[3][3];
int ans[3];
vector<char> one;
vector<P> two;
void go2(char c[],int n) {
	if (n == 1) {
		bool no = false;
		for (int k = 0; k < one.size(); k++) {
			if (c[0] == one[k]) {
				no = true;
				break;
			}
		}
		if (!no) {
			one.push_back(c[0]);
			ans[n]++;
		}
	}
	else {
		bool no = false;
		for (int k = 0; k < two.size(); k++) {
			if (c[0] == two[k].first && c[1] == two[k].second) {
				no = true;
				break;
			}
			else if (c[0] == two[k].second && c[1] == two[k].first) {
				no = true;
				break;
			}
		}
		if (!no) {
			two.push_back({ c[0],c[1] });
			ans[n]++;
		}
	}
}
void go(int n) {
	map<char, int> m;
	for (int i = 0; i < 3; i++) {
		m.clear();
		char c[3] = { '\0', };
		int idx = 0;
		for (int j = 0; j < 3; j++) {
			m[board[i][j]]++;
		}

		map<char, int>::iterator it;
		for (it = m.begin(); it != m.end(); it++) {
			c[idx++] = it->first;
		}
		if (m.size() == n) {
			go2(c, n);
		}
	}
	for (int j = 0; j < 3; j++) {
		m.clear();
		char c[3] = { '\0', };
		int idx = 0;
		for (int i = 0; i < 3; i++) {
			m[board[i][j]]++;
		}

		map<char, int>::iterator it;
		for (it = m.begin(); it != m.end(); it++) {
			c[idx++] = it->first;
		}
		if (m.size() == n) {
			go2(c, n);
		}
	}
	m.clear();
	char d[3] = { '\0', };
	char e[3] = { '\0', };
	int idx1 = 0;
	int idx2 = 0;
	for (int i = 0, j = 0; i < 3; i++, j++) {
		m[board[i][j]]++;
	}
	map<char, int>::iterator it;
	for (it = m.begin(); it != m.end(); it++) {
		d[idx1++] = it->first;
	}
	if (m.size() == n) {
		go2(d, n);
	}
	m.clear();
	for (int i = 0, j = 2; i < 3; i++, j--) {
		m[board[i][j]]++;
	}
	for (it = m.begin(); it != m.end(); it++) {
		e[idx2++] = it->first;
	}
	if (m.size() == n) {
		go2(e, n);
	}
}
int main() {
	// 같은거는 치지 않는다.
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			scanf(" %c", &board[i][j]);
		}
	}

	for (int i = 1; i <= 2; i++) go(i);
	printf("%d\n%d\n", ans[1], ans[2]);
	return 0;
}