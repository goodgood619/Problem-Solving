
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
typedef pair<int,int> P;
typedef pair<pair<int, int>,int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { -1,0,1,0 };
int goy[4] = { 0,1,0,-1 };
int n, m;
vector<int> v1, v2;
bool visited[500005];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%d", &num);
		v1.push_back(num);
	}
	for (int j = 0; j < m; j++) {
		int num;
		scanf("%d", &num);
		v2.push_back(num);
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	for (int i = 0; i < n; i++) {
		vector<int>::iterator it;
		it = lower_bound(v2.begin(), v2.end(), v1[i]);
		if (it == v2.end()) continue;
		if (*it == v1[i]) visited[i] = true;
	}
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) ans.push_back(v1[i]);
	}
	if (ans.size() == 0) printf("0\n");
	else {
		printf("%d\n", ans.size());
		for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
	}
	return 0;
}