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
int n,first;
int main() {
	scanf("%d", &n);
	scanf("%d", &first);
	vector<int> v;
	for (int i = 1; i < n; i++) {
		int num;
		scanf("%d", &num);
		v.push_back(num);
	}
	if (n == 1) {
		printf("0\n");
		return 0;
	}
	int ok = 0, cnt = 0;
	// 5,8,6일때 그냥 3이아니라 2명이므로, 직접 다해보는게 맘편함
	while (1) {
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++) {
			if (first <= v[i]) {
				first++;
				cnt++;
				v[i]--;
				break;
			}
			else { //무조건 1등
				ok = 1;
				break;
			}
		}
		if (ok) break;
	}
	printf("%d\n",cnt);
	return 0;
}