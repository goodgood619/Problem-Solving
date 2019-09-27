#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
int n,ans=1e9;
int people[11];
vector<vector<int>> a;
vector<int> v,temp;
bool visited[11], visited2[11];
void dfs2(int here,vector<int> &v) {
	visited2[here] = true;
	for (int i = 0; i < a[here].size(); i++) {
		int next = a[here][i];
		if (!visited2[next]) {
			int ok = 0;
			for (int j = 0; j < v.size(); j++) {
				if (v[j] == next) {
					ok = 1;
					break;
				}
			}
			if(ok) dfs2(next, v);
		}
	}
}
void bfs() { //인접한지에 대한 유무를 체크해야함

	int area = 0;
	memset(visited2, false, sizeof(visited2));
	for (int i = 0; i < v.size(); i++) {
		if (!visited2[v[i]]) {
			dfs2(v[i],v);
			area++;
		}
	}
	for (int i = 0; i < temp.size(); i++) {
		if (!visited2[temp[i]]) {
			dfs2(temp[i],temp);
			area++;
		}
	}
	if (area == 2) {
		int area1cnt = 0, area2cnt = 0;
		for (int i = 0; i < v.size(); i++) {
			area1cnt += (people[v[i]]);
		}
		for (int i = 0; i < temp.size(); i++) {
			area2cnt += (people[temp[i]]);
		}
		ans = min(ans, abs(area1cnt - area2cnt));
	}
}
void dfs(int here,int depth,int cnt) {
	if (cnt==depth) {
		temp.clear();
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) temp.push_back(i);
		}
		bfs();
		return;
	}
	for (int i = here; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			v.push_back(i);
			dfs(i + 1,depth,cnt+1);
			v.pop_back();
			visited[i] = false;
		}
	}
}
int main()
{
	scanf("%d", &n);
	a.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		scanf(" %d", &people[i]);
	}
	for (int i = 1; i <= n; i++) {
		int cnt;
		scanf("%d", &cnt);
		for (int j = 1; j <= cnt; j++) {
			int next;
			scanf("%d", &next);
			a[i].push_back(next);
		}
	}
	for (int i = 1; i < n; i++) {
		dfs(1,i,0);
	}
	ans == 1e9 ? printf("-1\n") : printf("%d\n", ans);
	return 0;
}