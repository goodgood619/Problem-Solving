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
bool visited[2005][2005];
int n;
int main() {
	scanf("%d", &n);
	int sx = 1002, sy = 1002;
	visited[sx][sy] = true;
	for (int i = 0; i < n; i++) {
		char c;
		scanf(" %c", &c);
		if (c == 'E') {
			sx += 1;
			visited[sx][sy] = true;
		}
		else if (c == 'W') {
			sx -= 1;
			visited[sx][sy] = true;
		}
		else if (c == 'S') {
			sy -= 1;
			visited[sx][sy] = true;
		}
		else {
			sy += 1;
			visited[sx][sy] = true;
		}
	}
	int ans = 0;
	for (int i = 0; i < 2005; i++) {
		for (int j = 0; j < 2005; j++) {
			ans += (visited[i][j] == true);
		}
	}
	printf("%d\n", ans);
	return 0;
}