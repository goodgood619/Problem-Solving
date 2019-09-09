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
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
int n;
int board[105][105];
vector<int> v;
int bfs(int low, int high) {
	bool visited[105][105] = { false, };
	queue<PPP> q;
	if (board[1][1]<low || board[1][1]>high) return 0;
	q.push({ board[1][1],{ 1,1 } });
	visited[1][1] = true;
	while (!q.empty()) {
		int num = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		if (x == n && y == n) return 1;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + gox[i];
			int ny = y + goy[i];
			if (nx<1 || nx>n || ny<1 || ny>n || visited[nx][ny])  continue;
			if (!visited[nx][ny] && board[nx][ny] >= low && board[nx][ny] <= high) {
				visited[nx][ny] = true;
				q.push({ board[nx][ny],{ nx,ny } });
			}
		}
	}
	return 0;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %d", &board[i][j]);
			v.push_back(board[i][j]);
		}
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	int left = 0, right = 0;
	int ans = 1e9;
	while(1){
		if (left >= v.size() || right >= v.size()) break;
		int ok = 0;
		while (1) {
			if (right >= v.size() || left >= v.size()) break;
			if (bfs(v[left], v[right])) {
				ok = 1;
				break;
			}
			else {
				right++;
			}
		}
		if (ok) {
			ans = min(ans, v[right] - v[left]);
			left++;
		}
	}
	printf("%d\n", ans);
	return 0;
}