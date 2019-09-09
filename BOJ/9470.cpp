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
	int t;
	scanf("%d", &t);
	while (t--) {
		int k, m, p;
		scanf("%d%d%d", &k, &m, &p);
		a.clear();
		a.resize(m + 1);
		queue<int> q;
		int indegree[1005] = { 0, };
		int dist[1005] = { 0, };
		int cnt[1005] = { 0, };
		for (int i = 1; i <= p; i++) {
			int first, second;
			scanf("%d%d", &first, &second);
			a[first].push_back(second);
			indegree[second]++;
		}
		for (int i = 1; i <= m; i++) {
			if (indegree[i] == 0) {
				q.push(i);
				dist[i] = 1;
			}
		}
		int Max = 0;
		while (!q.empty()) {
			int here = q.front();
			q.pop();
			if (cnt[here] > 0) dist[here] += 1;
			for (int i = 0; i < a[here].size(); i++) {
				int next = a[here][i];
				if (dist[next] < dist[here]) {
					dist[next] = dist[here];
					cnt[next] = 0;
				}
				else if (dist[next] == dist[here]) cnt[next]++;
				indegree[next]--;
				if (indegree[next] == 0) {
					q.push(next);
				}
			}
			Max = max(Max, dist[here]);
		}
		printf("%d %d\n", k, Max);
	}
	return 0;
}