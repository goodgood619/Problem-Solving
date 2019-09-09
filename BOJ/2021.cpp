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
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
vector<vector<int>> station;
vector<vector<int>> route;
int n, m, st, en;
bool visited[100005];
bool routevisited[100005];
int dist[100005];
int bfs(int here, int en) {
	//시작점의 노선을 전부다 넣어준다
	queue<int> q;
	q.push(here);
	for (int j = 0; j < station[here].size(); j++) { // 시작역의 노선이 여러개 가능
		int h = station[here][j];
		routevisited[h] = true;
		for (int i = 0; i < route[h].size(); i++) { // 정해진 노선을 전부다 넣어준다 
			q.push(route[h][i]);
			visited[route[h][i]] = true;
		}
	}
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		if (here == en) return dist[here];
		//here역에서 station정보가 여러개가 있는지 체크(즉 갈수있는지 없는지)
		for (int i = 0; i < station[here].size(); i++) {
			int nosun = station[here][i];
			if (routevisited[nosun]) continue;
			else { //n번 노선을 전부다 넣어주는데, here랑 겹치는건 안넣어줌
				routevisited[nosun] = true;
				for (int j = 0; j < route[nosun].size(); j++) {
					if (here == route[nosun][j] || visited[route[nosun][j]]) continue;
					if (!visited[route[nosun][j]]) {
						visited[route[nosun][j]] = true;
						q.push(route[nosun][j]);
						dist[route[nosun][j]] = dist[here] + 1;
						if (route[nosun][j] == en) {
							return dist[route[nosun][j]];
						}
					}
				}
			}
		}
	}
	return -1;
}
int main() {
	scanf("%d%d", &n, &m);
	station.resize(n + 1);
	route.resize(m + 1);
	for (int i = 1; i <= m; i++) {
		while (1) {
			int num;
			scanf("%d", &num);
			if (num == -1) break;
			route[i].push_back(num);
			station[num].push_back(i);
		}
	}

	scanf("%d%d", &st, &en);
	printf("%d\n", bfs(st, en));
	return 0;
}