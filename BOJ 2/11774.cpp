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
int go[100005]; // 1은 현재정점에서 단방향을 그을수 있다,0은 그을수없다
int from[100005];
int to[100005];
// 트리 탐색에 있어서 최장경로가 제일 작아지도록 문제를변형하는 방법
// colording dfs를 떠올리면서, 현재정점에서 단방향을 그으면, 다음정점은 절대 그을수 없다
int main() {
	scanf("%d", &n);
	a.resize(n + 1);
	for (int i = 1; i < n; i++) {
		int first, second;
		scanf("%d%d", &first, &second);
		from[i] = first;
		to[i] = second;
		a[first].push_back(second);
		a[second].push_back(first);
	}
	memset(go, -1, sizeof(go));
	queue<int> q;
	q.push(1);
	go[1] = 0;
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		for (int i = 0; i < a[here].size(); i++) {
			int next = a[here][i];
			if (go[next] != -1) continue;
			go[next] = 1 - go[here];
			q.push(next);
		}
	}
	for (int i = 1; i < n; i++) {
		printf("%d\n", go[(from[i])]);
	}
	return 0;
}