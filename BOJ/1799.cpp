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
int gox[4] = { -1,1,1,-1 };
int goy[4] = { 1,1,-1,-1 };
int board[11][11];
vector<P> v, temp;
bool visited[11][11];
int n, Max;
// 현재 (x,y)위치에서 가능한 비숍들의 위치를 전부다 구하고, temp에 있는 기존애들이랑 겹치는 지 안겹치는지를 비교
bool check(int x, int y) {
	for (int i = 0; i <temp.size(); i++) {
		int px = temp[i].first, py = temp[i].second;
		int no = 0;
		if (abs(px - x) == abs(py - y)) return false;
	}

	return true;
}
void dfs(int x,int y,int cnt,int flag) {
	if (x > n) return;
	if (y > n) {
		if (!flag) flag = 1;
		else flag = 0;
		x++;
		if (flag) y = 2;
		else y = 1;
	}
	Max = max(Max, cnt);
	if (board[x][y] == 1 && !visited[x][y] && check(x,y)) {
		temp.push_back({ x,y });
		visited[x][y] = true;
		dfs(x, y + 2,cnt+1,flag);
		temp.pop_back();
		visited[x][y] = false;
	}
	dfs(x, y + 2, cnt,flag);
}
void dfs2(int x, int y, int cnt, int flag) {
	if (x > n) return;
	if (y > n) {
		if (!flag) flag = 1;
		else flag = 0;
		x++;
		if (flag) y = 1;
		else y = 2;
	}
	Max = max(Max, cnt);
	if (board[x][y] == 1 && !visited[x][y] && check(x,y)) {
		temp.push_back({ x,y });
		visited[x][y] = true;
		dfs2(x, y + 2, cnt + 1, flag);
		temp.pop_back();
		visited[x][y] = false;
	}
	dfs2(x, y + 2, cnt, flag);
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %d", &board[i][j]);
		}
	}

	
	dfs(1,1,0,0);
	int sum = Max;
	Max = 0;
	memset(visited, false, sizeof(visited));
	dfs2(1, 2, 0, 0);
	sum += Max;
	printf("%d\n", sum);
	return 0;
}