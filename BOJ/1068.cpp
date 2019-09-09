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
typedef pair<pair<int, int>, pair<int, int>> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
using namespace std;
int n,del,cnt;
vector<vector<int>> a;
bool visited[51];
void dfs(int here) {
	if (a[here].size() == 0) cnt++;
	visited[here] = true;
	for (int i = 0; i < a[here].size(); i++) {
		int next = a[here][i];
		if (!visited[next]) dfs(next);
	}
}
int main() {
	scanf("%d", &n);
	int st = 0;
	a.resize(n + 1);
	for (int i = 0; i < n; i++) {
		int par;
		scanf("%d", &par);
		if (par == -1) 	st = i;
		else a[par].push_back(i);
	}
	scanf("%d", &del);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < a[i].size(); j++) {
			int next = a[i][j];
			if (del == next) {
				a[i].erase(a[i].begin() + j);
			}
		}
	}
	dfs(st);
	del == st ? printf("0\n") : printf("%d\n", cnt);
	return 0;
}