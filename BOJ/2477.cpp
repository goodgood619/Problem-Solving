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
int gox[4] = { 0, 0,1,-1 };
int goy[4] = { 1, -1,0,0 };
int k;
bool visited[2005][2005];
bool sq[2005][2005];
int bfs(){
	queue<P> q;
	q.push({ 1,1 });
	visited[1][1] = true;
	int cnt = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx < 1 || nx>2000 || ny < 1 || ny>2000 || visited[nx][ny] || sq[nx][ny]) continue;
			else if (!visited[nx][ny] && !sq[nx][ny]) {
				visited[nx][ny] = true;
				cnt++;
				q.push({ nx,ny });
			}
		}
	}
	int t = 0;
	for (int i = 1; i <= 1999; i++) {
		for (int j = 1; j <= 1999; j++) {
			if (!visited[i][j] &&!visited[i][j+1] && !visited[i+1][j] && !visited[i+1][j+1]) t++;
		}
	}

	return t;
}
int main() {
	scanf("%d", &k);
	vector<int> v1,v2;
	int sx = 1000, sy = 1000;
	for (int i = 1; i <= 6; i++) {
		int dir, num;
		scanf(" %d%d", &dir, &num);
		dir--;

		for (int j = 0; j <num; j++) {
			int nx = sx + gox[dir];
			int ny = sy + goy[dir];
			sq[nx][ny] = true;
			sx = nx, sy = ny;
		}


	}

	printf("%d\n",k*bfs());
	return 0;
}