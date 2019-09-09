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
int t;
vector<int> v;
void go(int sum, int index, int depth) {
	if (index == depth) {
		return;
	}
	v.push_back(sum);
	go(sum * 10 + 5, index + 1, depth);
	go(sum * 10 + 8, index + 1, depth);
}
int main(void) {
	go(0, 0, 7);
	sort(v.begin(), v.end());
	scanf("%d", &t);
	while (t--) {
		int a, b, c;
		int cnt = 0;
		int a1[55] = { 0, }, a2[55] = { 0, }, a3[55] = {0,};
		map<int, int> m;
		scanf("%d", &a);
		for (int i = 1; i <= a; i++) scanf("%d", &a1[i]);
		scanf("%d", &b);
		for (int i = 1; i <= b; i++) scanf("%d", &a2[i]);
		scanf("%d", &c);
		for (int i = 1; i <= c; i++) scanf("%d", &a3[i]);
		for (int i = 1; i <= a; i++) {
			for (int j = 1; j <= b; j++) {
				for (int k = 1; k <= c; k++) {
					vector<int>::iterator it = lower_bound(v.begin(), v.end(), a1[i] + a2[j] + a3[k]);
					if (*it == a1[i] + a2[j] + a3[k] && m.count(*it) == 0) {
						m[*it] = 1;
						cnt++;
					}
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}