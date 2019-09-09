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
typedef pair<double, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
vector<vector<int>> a;
int main() {
	int n,m;
	scanf("%d%d", &n,&m);
	a.resize(n + 1);
	int make[1005] = { 0, };
	int indegree[1005] = { 0, };
	queue <int> q;
	vector<int> v;
	for (int i = 1; i <= m; i++) {
		int cnt;
		scanf("%d", &cnt);
		int first = 0;
		int second = 0;
		for (int j = 1; j <= cnt; j++) {
			int num;
			scanf("%d", &num);
			if (first == 0) {
				first = num;
				continue;
			}
			else {
				second = num;
				a[first].push_back(second);
				indegree[second]++;
				first = second;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		v.push_back(here);
		for (int i = 0; i < a[here].size(); i++) {
			int next = a[here][i];
			indegree[next]--;
			if (indegree[next] == 0) {
				q.push(next);
			}
		}
	}

	if (v.size() != n) {
		printf("0\n");
	}
	else {
		for (int i = 0; i < v.size(); i++) {
			printf("%d\n", v[i]);
		}
	}
	return 0;
}