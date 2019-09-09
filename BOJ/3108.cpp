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
typedef pair<pair<int, int>, int> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { 0,0,1,-1 };
int goy[4] = { 1,-1,0,0 };
int n;
vector<vector<int>> a;
bool visited[1005];
void dfs(int here) {
	visited[here] = true;
	for (int i = 0; i < a[here].size(); i++) {
		int next = a[here][i];
		if (!visited[next]) {
			dfs(next);
		}
	}
}
int main() {
	scanf("%d", &n);
	a.resize(n + 1);
	vector<PPP> v;
	for (int i = 1; i <= n; i++) {
		int fx, fy, ex, ey;
		scanf("%d%d%d%d", &fx, &fy, &ex, &ey);
		v.push_back({ { fx,fy }, {ex,ey} });
	}
	v.push_back({ {0,0 }, { 0,0 } });
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			if(i==j) continue;
			int fx = v[i].first.first, fy = v[i].first.second, ex = v[i].second.first, ey = v[i].second.second;
			int fx2 = v[j].first.first, fy2 = v[j].first.second, ex2 = v[j].second.first, ey2 = v[j].second.second;
			if (ex > ex2 && ey > ey2 && fx<fx2 && fy<fy2) continue; // j직사각형이 i에 완전히 들어갈때
			if (ex2 > ex && ey2 > ey && fx > fx2 && fy > fy2)continue; // i직사각형이 j에 완전히 들어갈때
			if (fx <= ex2 && ex >= fx2 && fy <= ey2 && ey >= fy2) { // 그냥 겹치기(그림을 그려보면 쉽다)
				a[i].push_back(j);
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i <= n; i++) {
		if (!visited[i]) {
			dfs(i);
			cnt++;
		}
	}
	printf("%d\n", cnt - 1);
	return 0;
}