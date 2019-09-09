#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
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
#define mod 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0};
int goy[4] = { 1,0,0,-1};
int n;
deque<int> d;
int main() {
	int here = 1;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		char c;
		scanf(" %c", &c);
		if (c == 'A') {
			char c1;
			scanf(" %c", &c1);
			if (c1 == 'L') {
				d.push_front(here);
				here++;
			}
			else {
				d.push_back(here);
				here++;
			}
		}
		else {
			char c1;
			int num;
			int p = 0;
			scanf(" %c", &c1);
			if (c1 == 'L') {
				scanf("%d", &num);
				while (p < num) {
					d.pop_front();
					p++;
				}
			}
			else {
				scanf("%d", &num);
				while (p < num) {
					d.pop_back();
					p++;
				}
			}
		}
	}
	while (!d.empty()) {
		printf("%d\n", d.front());
		d.pop_front();
	}
	return 0;
}