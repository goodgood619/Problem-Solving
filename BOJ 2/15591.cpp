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
vector<vector<P>> a;
int n, m;
bool visited[5005];
int main() {
	scanf("%d%d", &n, &m);
	a.resize(n + 1);
	for (int i = 1; i <= n-1; i++) {
		int first, second, cost;
		scanf("%d%d%d", &first, &second, &cost);
		a[first].push_back({ second,cost });
		a[second].push_back({ first,cost });
	}
	for (int i = 1; i <= m; i++) {
		int w, start;
		scanf("%d%d", &w, &start);

		queue<int> q;
		q.push(start);
		int cnt = 0;
		memset(visited, false, sizeof(visited));
		visited[start] = true;
		while (!q.empty()) {
			int here = q.front();
			q.pop();
			for (int i = 0; i < a[here].size(); i++) {
				int next = a[here][i].first;
				int nextcost = a[here][i].second;
				if (nextcost >= w && !visited[next]) {
					visited[next] = true;
					q.push( next);
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}