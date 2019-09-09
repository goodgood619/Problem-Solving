
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
typedef pair<int, int> P;
typedef pair<int, pair<ll, char>> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
typedef pair<ll, ll> p;
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
string s="hwdelor";
// h와 w는 절대 0이 아니다
int n,ok,ans1,ans2;
bool visited[10];
vector<int> temp;
void go(int index) {
	if (ok) return;
	if (temp.size() >= 2) {
		if (temp[0] == 0 || temp[1] == 0) return;
	}
	if (index == 7) {
		map<char, int> m;
		int sum1 = 0;
		int sum2 = 0;
		for (int i = 0; i < temp.size(); i++) {
			if (i == 0) m['h'] = temp[i];
			else if (i == 1) m['w'] = temp[i];
			else if (i == 2) m['d'] = temp[i];
			else if (i == 3) m['e'] = temp[i];
			else if (i == 4) m['l'] = temp[i];
			else if (i == 5) m['o'] = temp[i];
			else if (i == 6) m['r'] = temp[i];
		}
		sum1 += (m['h'] * 1e4) + (m['e'] * 1e3) + (m['l'] * 1e2) + (m['l'] * 1e1) + (m['o']);
		sum2 += (m['w'] * 1e4) + (m['o'] * 1e3) + (m['r'] * 1e2) + (m['l'] * 1e1) + (m['d']);
		if (sum1 + sum2 == n) {
			ans1 = sum1;
			ans2 = sum2;
			ok = 1;
		}
		return;
	}

	for (int i = 0; i < 10; i++) {
		if (!visited[i]) {
			visited[i] = true;
			temp.push_back(i);
			go(index + 1);
			temp.pop_back();
			visited[i] = false;
		}
	}
}
int main() {
	scanf("%d", &n);
	go(0);
	if (ok) {
		printf("  %d\n", ans1);
		printf("+ %d\n", ans2);
		printf("-------\n");
		if (n >= 100000) printf(" %d\n", n);
		else printf("  %d\n", n);
	}
	else printf("No Answer\n");
	return 0;
}
