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
int gox[4] = { 0, -1,0,1};
int goy[4] = { 1, 0,-1,0};
int n, m, k;
int board[103][103];
bool visited[103][103];
void go(int x, int y, int d, int g) {
	vector<int> route,newroute;
	if (g >= 2) {
		route.push_back(d), route.push_back((d + 1) % 4);
		newroute.push_back((d + 1) % 4);
		for (int i = 2; i <= g; i++) {
			vector<int> temp;
			for (int j = newroute.size() - 1; j >= 0; j--) {
				temp.push_back((newroute[j] + 1) % 4);
			}
			for (int j = 0; j < newroute.size(); j++) {
				temp.push_back(newroute[j]);
			}
			for (int j = 0; j < temp.size(); j++) {
				route.push_back(temp[j]);
			}
			newroute = temp;
		}
	}
	else if (g == 1) {
		route.push_back(d), route.push_back((d + 1) % 4);
	}
	else {
		route.push_back(d);
	}
	visited[x][y] = true;
	for (int i = 0; i < route.size(); i++) {
		int dir = route[i];
		int nx = x + gox[dir];
		int ny = y + goy[dir];
		visited[nx][ny] = true;
		x = nx, y = ny;
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x, y, d, g;
		scanf("%d%d%d%d", &x, &y, &d, &g);
		go(y,x, d, g);
	}
	int ans = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (j + 1 > 100 || i + 1 > 100) continue;
			if (visited[i][j] && visited[i][j + 1] && visited[i + 1][j] && visited[i + 1][j + 1]) {
				ans++;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}