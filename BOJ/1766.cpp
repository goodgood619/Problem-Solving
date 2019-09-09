#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <deque>
#include <functional>
using namespace std;
int n, m;
vector<vector<int>> a;
int indegree[32001];
priority_queue<int, vector<int>, greater<int>> pq;
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
		if (!indegree[i]) pq.push(i);
	}
	while (!pq.empty()) {
		int here = pq.top();
		pq.pop();
		printf("%d ", here);
		for (int i = 0; i < a[here].size(); i++) {
			int next = a[here][i];
			indegree[next]--;
			if (!indegree[next]) pq.push(next);
		}
	}
	return 0;
}