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
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[6] = { -2,-2,0,0,2,2 };
int goy[6] = { -1,1,2,-2,-1,1 };
int rx[4] = { 1,5,10,50 };
int n,sx,sy,ex,ey;
bool visited[1005];
int dist[205][205];
int bfs() {
	queue<int> q;
	int cnt = 0;
	for (int j = 0; j < 4; j++) {
		q.push(rx[j]);
	}
	for (int i = 1; i < n; i++) {
		memset(visited, false, sizeof(visited));
		int Size = q.size();
		while (Size--) {
			int x = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int next = x + rx[i];
				if (!visited[next]) {
					visited[next] = true;
					q.push(next);
				}
			}
		}
	}
	return q.size();
}
int main() {
	scanf("%d", &n);
	printf("%d\n",bfs());
	return 0;
}