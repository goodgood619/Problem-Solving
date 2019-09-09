#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <deque>
using namespace std;
int n, m;
int indegree[32001];
queue <int> q;
vector<vector<int>> a;
int main() {
	scanf("%d%d", &n, &m);
	a.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		a[first].push_back(second);
		indegree[second]++;
	}
	for (int i = 1; i <= n; i++) {
		if (!indegree[i]) q.push(i);
	}
	while (!q.empty()) {
		int here = q.front();
		printf("%d ", here);
		q.pop();
		for (int i = 0; i < a[here].size(); i++) {
			int next = a[here][i];
			indegree[next]--;
			if (!indegree[next]) q.push(next);
		}
	}
	return 0;
}