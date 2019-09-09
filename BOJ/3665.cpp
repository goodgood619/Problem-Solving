
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
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		int team[505] = { 0, };
		int board[505][505] = { 0, };
		int indegree[505] = { 0, };
		bool no = false;
		queue<int> q;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &team[i]);
		}
		//작년 기준으로 이긴것
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				board[team[i]][team[j]] = 1;
			}
		}
		scanf("%d", &m);
		for (int i = 1; i <= m; i++) {
			int first, second;
			scanf("%d%d", &first, &second);
			if (board[first][second] == 1) {
				board[first][second] = 0;
				board[second][first] = 1;
			}
			else if (board[second][first]==1) {
				board[second][first] = 0;
				board[first][second] = 1;
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (board[i][j] == 1) {
					indegree[j]++;
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		vector<int> ans;
		while (!q.empty()) {
			// 등수가 여러명이므로 불분명함
			if (q.size() >= 2) {
				no = true;
				break;
			}
			int here = q.front();
			q.pop();
			ans.push_back(here);
			for (int i = 1; i <= n; i++) {
				if (board[here][i] == 1) {
					indegree[i]--;
					if (indegree[i] == 0) {
						q.push(i);
					}
				}
			}
		}
		if (no) {
			printf("?\n");
			continue;
		}
		if (ans.size() < n) {
			printf("IMPOSSIBLE\n");
			continue;
		}
		for (int i = 0; i < ans.size(); i++) {
			printf("%d ", ans[i]);
		}
		printf("\n");

	}
	return 0;
}