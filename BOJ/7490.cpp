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
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
int t,n;
vector<int> v;
string s;
// _를 우선적으로 붙인다
bool calc(string s) {
	int sum = 0;
	int here = 1;
	for (int i = 2; i <= n; i++) {
		if (s[i - 2] == ' ') {
			if (here < 0) here = here * 10 + i*-1;
			else here = here * 10 + i;
		}
		else if(s[i-2]=='+') {
			sum += here;
			here = i;
		}
		else {
			sum += here;
			here = -i;
		}
	}
	sum += here;
	if (sum == 0) return true;
	else return false;
}
void go(int index,string s) {
	if (index == v.size()-1) {
		if (calc(s)) {
			for (int i = 0; i < v.size(); i++) {
				printf("%d", v[i]);
				if (i == v.size() - 1) break;
				printf("%c", s[i]);
			}
			printf("\n");
		}
		return;
	}
	go(index + 1, s + ' ');
	go(index + 1, s + '+');
	go(index + 1, s + '-');
}
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		v.clear();
		s.clear();
		for (int i = 1; i <= n; i++)v.push_back(i);
		go(0,"");
		printf("\n");
	}
	return 0;
}