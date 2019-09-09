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
typedef pair<double, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<double, pair<int, int>> PPP;
typedef pair<pair<int, int>, pair<int, int>> PPPP;
int gox[4] = { -1,0,1,0 };
int goy[4] = { 0,1,0,-1 };
int t, Case = 1,n;
bool visited[1001][1001];
int main() {
	int c, r,k;
	scanf("%d%d%d", &c, &r, &k);
	if (k > c*r) printf("0\n");
	else {
		int cnt = 1;
		int sx = r;
		int sy = 1;
		int dir = 0;
		while (cnt < k) {
			visited[sx][sy] = cnt++;
			int nx = sx + gox[dir];
			int ny = sy + goy[dir];
			if (nx<1 || nx>r || ny<1 || ny>c || visited[nx][ny]) {
				dir += 1;
				dir %= 4;
				nx = sx + gox[dir];
				ny = sy + goy[dir];
			}
			sx = nx, sy = ny;

		}
		printf("%d %d\n", sy, r - sx + 1);
	}

	return 0;
}