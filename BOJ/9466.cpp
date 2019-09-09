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
typedef pair<ll, ll> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int t;
vector<vector<int>> a;
int main() {
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int indegree[100005] = { 0, };
		a.clear();
		a.resize(n + 1);
		for (int i = 1; i <= n; i++) {
			int num;
			scanf("%d", &num);
			a[i].push_back(num);
			indegree[num]++;
		}
		queue<int> q;
		for (int i = 1; i <= n; i++) {
			if (indegree[i] == 0) q.push(i);
		}
		int cnt = 0;
		while (!q.empty()) {
			int here = q.front();
			q.pop();
			cnt++;
			for (int i = 0; i < a[here].size(); i++) {
				int next = a[here][i];
				indegree[next]--;
				if (indegree[next] == 0) {
					q.push(next);
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}