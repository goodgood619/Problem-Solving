#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <map>
#include <set>
#include <list>
#include <climits>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
int indegree[1005];
int value[1005];
int cnt[1005];
queue<int> q;
int n,m;
string s;
vector<vector<int>> a;
int main() {
	scanf("%d%d", &n, &m);
	a.resize(n + 1);
	set<int> c;
	for (int i = 1; i <= m; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		a[first].push_back(second);
		indegree[second]++;
	}
	int st, en, k;
	scanf("%d%d%d", &st, &en, &k);
	for (int i = 1; i <= k; i++) {
		int num;
		scanf("%d", &num);
		c.insert(num);
	}
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) q.push(i);
	}
	value[st] = 1;
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		if (c.find(here) != c.end()) cnt[here]++;
		for (int i = 0; i < a[here].size(); i++) {
			int next = a[here][i];
			if (cnt[here] == cnt[next]) value[next] += value[here];
			else if (cnt[next] < cnt[here]) {
				cnt[next] = cnt[here];
				value[next] = value[here];
			}
			indegree[next]--;
			if (indegree[next] == 0) q.push(next);
		}
	}
	if (cnt[en] == c.size()) printf("%d\n", value[en]);
	else printf("0");
	return 0;
}