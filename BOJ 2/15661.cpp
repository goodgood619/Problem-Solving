#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <functional>
#include <map>
#include <iostream>
#include <string>
#include <deque>
#include <stack>
#include <math.h>
#include <set>
#include <climits>
using namespace std;
typedef long long ll;
int n, k;
int board[25][25];
bool visited[25];
int ans = 1e9;
void go(int index, int cnt, int depth) {
	if (cnt == depth) {
		vector<int> start, link;
		for (int i = 1; i <= n; i++) {
			if (visited[i]) start.push_back(i);
			else link.push_back(i);
		}
		int startsum = 0;
		int linksum = 0;
		for (int i = 0; i < start.size(); i++) {
			for (int j = i + 1; j < start.size(); j++) {
				startsum += (board[start[i]][start[j]] + board[start[j]][start[i]]);
			}
		}
		for (int i = 0; i < link.size(); i++) {
			for (int j = i + 1; j < link.size(); j++) {
				linksum += (board[link[i]][link[j]] + board[link[j]][link[i]]);
			}
		}
		ans = min(ans, abs(startsum - linksum));
		return;
	}
	for (int i = index; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			go(i + 1, cnt + 1, depth);
			visited[i] = false;
		}
	}
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %d", &board[i][j]);
		}
	}
	for (int k = 1; k < n; k++) {
		go(1, 0, k);
	}
	printf("%d\n", ans);
	return 0;
}