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
typedef pair<int, ll> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[8] = { 0,1,-1,0,1,-1,-1,1 };
int goy[8] = { 1,0,0,-1,1,-1,1,-1 };
int n,cnt,sx,sy;
char board[55][55];
int height[55][55];
bool visited[55][55];
int dfs(int x, int y, int Minheight, int Maxheight) {
	if (x<1 || x>n || y<1 || y>n || height[x][y]<Minheight || height[x][y]>Maxheight || visited[x][y]) return 0;
	int ret = 0;
	if (board[x][y] == 'K') ret++;
	visited[x][y] = true;
	for (int i = 0; i < 8; i++) {
		int nx = x + gox[i];
		int ny = y + goy[i];
		ret+=dfs(nx, ny, Minheight, Maxheight);
	}
	return ret;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %c", &board[i][j]);
			if (board[i][j] == 'K') cnt++;
			if (board[i][j] == 'P') sx = i, sy = j;
 		}
	}
	vector<int> v;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %d", &height[i][j]);
			v.push_back(height[i][j]);
		}
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	int right = 0;
	int ans = 1e9;
	for (int i = 0; i < v.size() && right<v.size(); i++) {
		while (1) { //안되면,right를 늘린다, 되면, break하고 left를 늘린다
			memset(visited, false, sizeof(visited));
			if (right == v.size()) break;
			if (dfs(sx, sy, v[i],v[right])==cnt) break;
			else {
				right++;
			}
		}
		if (right == v.size()) break;
		ans = min(ans,abs(v[i] - v[right]));
	}
	printf("%d\n", ans);
	return 0;
}