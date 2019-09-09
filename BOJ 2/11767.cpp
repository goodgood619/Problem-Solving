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
typedef pair<int,pair<int, int>> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
int n, m,s,t;
ll cnt[105];
ll cur[105];
bool visited[105];
vector<vector<int>> a;
int main() {
	scanf("%d%d%d%d", &n, &m, &s, &t);
	a.resize(n);
	for (int i = 1; i <= m; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		a[first].push_back(second);
		a[second].push_back(first);
	}
	// 시작점에서 인접한 정점들에게 virus수를 전달 
	// 그다음 총 갯수 집계 그리고 해당시간될때까지 반복
	queue<int> q;
	ll Max = 0;
	for (int i = 1; i <= t; i++) {
		Max = 0;
		memset(cnt, 0, sizeof(cnt));
		memset(visited, false, sizeof(visited));
		if (i == 1) {
			for (int j = 0; j < a[s].size(); j++) {
				int next = a[s][j];
				cnt[next]+=1;
				cur[next] = 1;
				q.push(next);
			}
			Max += a[s].size();

		}
		else {
			queue<int> tq;
			while (!q.empty()) {
				int here = q.front();
				q.pop();
				for (int i = 0; i < a[here].size(); i++) {
					int next = a[here][i];
					cnt[next] += cur[here];
					if (!visited[next]) {
						visited[next] = true;
						tq.push(next);
					}
				}
			}
			memset(cur, 0, sizeof(cur));
			for (int i = 0; i < n; i++) {
				cur[i] = cnt[i];
				Max += cnt[i];
			}
			q = tq;
		}
	}
	printf("%lld\n", Max);
	return 0;
}