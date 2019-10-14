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
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = {0,-1,0,1 };
int goy[4] = { 1,0,-1,0 };
struct position {
	int x;
	int y;
};
void go(int y,int x,int d,int g,int **visited) {
	vector<int> route,temp;
	route.push_back(d);
	for (int i = 1; i <= g; i++) {
		vector<int> temp = route;
		for (int j = temp.size() - 1; j >= 0; j--) {
			route.push_back((temp[j] + 1) % 4);
		}
	}
	visited[x][y] = 1;
	for (int i = 0; i < route.size(); i++) {
		int nx = x + gox[route[i]], ny=y + goy[route[i]];
		visited[nx][ny] = 1;
		x = nx, y = ny;
	}
}
int main() {
	int** visited = new int* [101];
	for (int i = 0; i <=100; i++) visited[i] = new int[101];
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			visited[i][j] = 0;
		}
	}
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int y, x, d, g;
		scanf("%d%d%d%d", &y, &x, &d, &g);
		go(y, x, d, g, visited);
	}
	int ans = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (visited[i][j] == 1 && visited[i + 1][j] == 1 && visited[i][j + 1] == 1 && visited[i + 1][j + 1] == 1) ans++;
		}
	}
	printf("%d\n", ans);
	
	for (int i = 0; i <= 100; i++) delete[] visited[i];
	delete[] visited;
	return 0;
}