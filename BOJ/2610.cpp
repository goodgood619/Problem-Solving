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
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int board[105][105];
bool visited[105];
int n,m;
vector<vector<int>> a;
vector<vector<int>> path;
vector<int> v;
void dfs(int here) {
	visited[here] = true;
	v.push_back(here);
	for (int i = 0; i < a[here].size(); i++) {
		int next = a[here][i];
		if (!visited[next]) {
			dfs(next);
		}
	}
}
void floyd() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (board[i][j]>board[i][k]+board[k][j]) {
					board[i][j]=board[i][k]+board[k][j];
				}
			}
		}
	}
}
int main() {
	scanf("%d%d", &n,&m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			board[i][j] = 1e9;
		}
	}
	a.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		int first, second,cost;
		scanf("%d%d", &first, &second);
		board[first][second] = 1;
		board[second][first] = 1;
		a[first].push_back(second);
		a[second].push_back(first);
	}
	floyd();
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			v.clear();
			dfs(i);
			cnt++;
			path.push_back(v);
		}
	}
	printf("%d\n", cnt);
	int ans = 1e9;
	vector<int> v;
	for (int i = 0; i < path.size(); i++) {
		vector<int> temp = path[i];
		int cost = 0;
		int num = 0;
		ans = 1e9;
		if (temp.size() == 1) {
			v.push_back(temp[0]);
			continue;
		}
		for (int j = 0; j < temp.size(); j++) {
			cost = 0;
			for (int k = 0; k < temp.size(); k++) {
				if (j==k) continue;
				else {
					cost =max(cost,board[temp[j]][temp[k]]);
				}
			}
			if (ans > cost) {
				ans = cost;
				num = temp[j];
			}
		}
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		printf("%d\n", v[i]);
	}
	return 0;
}