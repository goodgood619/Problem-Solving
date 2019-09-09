
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
int n, m;
map<string, int> mm;
vector<vector<int>> a;
double ans[200];
bool visited[200];
void dfs(int here,double sum) {
	visited[here] = true;
	ans[here] += sum;
	for (int i = 0; i < a[here].size(); i++) {
		int next = a[here][i];
		if (!visited[next]) {
			dfs(next, sum / 2);
		}
	}
	visited[here] = false;
}
int main() {
	scanf("%d%d", &n, &m);
	string start;
	cin >> start;
	int cnt = 1;
	a.resize(200);
	if (mm.count(start) == 0) {
		mm[start] = cnt++;
	}
	for (int i = 1; i <= n; i++) {
		string child, parent1, parent2;
		cin >> child >> parent1 >> parent2;
		if (mm.count(child) == 0) mm[child] = cnt++;
		if (mm.count(parent1) == 0) mm[parent1] = cnt++;
		if (mm.count(parent2) == 0) mm[parent2] = cnt++;
		a[mm[parent1]].push_back(mm[child]);
		a[mm[parent2]].push_back(mm[child]);
	}
	dfs(mm[start],1);
	double Max = 0;
	string c;
	for (int i = 1; i <= m; i++) {
		string temp;
		cin >> temp;
		if (Max < ans[mm[temp]]) {
			Max = ans[mm[temp]];
			c = temp;
		}
	}
	printf("%s\n", c.c_str());
	return 0;
}

