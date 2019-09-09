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
typedef pair<int, int> P;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = {0,1,-1,0};
int goy[4] = {1,0,0,-1};
int n;
int main(void) {
	scanf("%d", &n);
	vector<int> ans,v;
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		v.push_back(num);
	}
	if (n == 1) printf("A\n");
	else if (n == 2) {
		if (v[0] == v[1]) printf("%d\n",v[0]);
		else printf("A\n");
	}
	else {
		int a = 0;
		int x = v[1] - v[0];
		int y = v[2] - v[1];
		if (x != 0) a = y / x;
		int b = v[1] - a * v[0];
		int no = 0;
		for (int i = 1; i < v.size(); i++) {
			if (v[i] == a * v[i - 1] + b) continue;
			else {
				no = 1;
				break;
			}
		}
		no == 1 ? printf("B\n") : printf("%d\n", a*v[v.size() - 1] + b);
	}
	return 0;
}