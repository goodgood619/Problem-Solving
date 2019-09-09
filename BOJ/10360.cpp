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
#define INF 1000000000
#define mod 1000000007
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<double, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { -1,0,1,0 };
int goy[4] = { 0,1,0,-1 };
int t, Case = 1, n, m;
vector <vector<pair<int, int>>> a;
int dist[1001];
bool visited[1001];
int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		a.clear();
		a.resize(n + 1);
		memset(visited, false, sizeof(visited));
		for (int i = 1; i <= m; i++) {
			int first, second, cost;
			scanf("%d%d%d", &first, &second, &cost);
			a[first].push_back({ second,cost });
		}
		for (int i = 0; i < n; i++) dist[i] = 1e9;
		dist[0] = 0;
		bool cycle = false;
		queue<int> q;
		for (int k = 1; k <= n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < a[i].size(); j++) {
					int next = a[i][j].first;
					int nextcost = a[i][j].second;
					if (dist[next] > dist[i] + nextcost && dist[i] != 1e9) {
						dist[next] = dist[i] + nextcost;
						if (k == n) {
							q.push(i);
							visited[i] = true;
							cycle = true;
						}
					}
				}
			}
		}
		bool check = false;
		if (dist[0] < 0) check = true;
		while (!q.empty()) { //음의 사이클에 걸렸지만, 다시 시작점 0으로 오기위함을 체크
			int here = q.front();
			if (here == 0) {
				check = true;
				break;
			}
			q.pop();
			for (int i = 0; i < a[here].size(); i++) {
				int next = a[here][i].first;
				if (!visited[next]) {
					visited[next] = true;
					q.push(next);
				}
			}
		}
		check ? printf("Case #%d: possible\n", Case++) : printf("Case #%d: not possible\n", Case++);
	}
	return 0;
}