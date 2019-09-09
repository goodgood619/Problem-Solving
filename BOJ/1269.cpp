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
typedef pair<int, pair<int, int>> PP;
typedef pair<pair<int, int>, pair<int, bool>> PPP;
int gox[4] = {0,1,-1,0};
int goy[4] = {1,0,0,-1};
int n, m;
vector<int> v1, v2;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) { 
		int num;
		scanf("%d", &num);
		v1.push_back(num);
	}
	for (int i = 0; i < m; i++) {
		int num;
		scanf("%d", &num);
		v2.push_back(num);
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	int same = 0;
	for (int i = 0; i < v1.size(); i++) {
		vector<int>::iterator it,it2;
		it = lower_bound(v2.begin(), v2.end(), v1[i]);
		it2 = lower_bound(v1.begin(), v1.end(), v1[i]);
		if (*it == *it2) same++;
	}
	printf("%d\n", v1.size() + v2.size() - same*2);
	return 0;
}

