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
using namespace std;
typedef long long ll;
#define INF 1000000000
typedef pair<int, int> P;
typedef pair<pair<int, int>, int> PP;
typedef pair<int, pair<int, int>> PPP;
int gox[4] = { 0,1,-1,0 };
int goy[4] = { 1,0,0,-1 };
// U:위,D:아래, R:오른쪽,L:왼쪽
bool check[15][15];
bool visited[15][15][15][15];
int solution(string dirs)
{
	int ans = 0;
	int sx = 5, sy = 5;
	for (int i = 0; i < dirs.size(); i++) {
		char here = dirs[i];
		if (here == 'U') {
			int nx = sx + gox[2];
			int ny = sy + goy[2];
			if (nx < 0 || nx>10 || ny < 0 || ny>10) continue;
			if (visited[sx][sy][nx][ny] || visited[nx][ny][sx][sy]) {
				sx = nx, sy = ny;
				continue;
			}
			visited[sx][sy][nx][ny] = true;
			ans++;
			sx = nx, sy = ny;
		}
		else if (here == 'D') {
			int nx = sx + gox[1];
			int ny = sy + goy[1];
			if (nx < 0 || nx>10 || ny < 0 || ny>10) continue;
			if (visited[sx][sy][nx][ny] || visited[nx][ny][sx][sy]) {
				sx = nx, sy = ny;
				continue;
			}
			visited[sx][sy][nx][ny] = true;
			ans++;
			sx = nx, sy = ny;
		}
		else if (here == 'L') {
			int nx = sx + gox[3];
			int ny = sy + goy[3];
			if (nx < 0 || nx>10 || ny < 0 || ny>10) continue;
			if (visited[sx][sy][nx][ny] || visited[nx][ny][sx][sy]) {
				sx = nx, sy = ny;
				continue;
			}
			visited[sx][sy][nx][ny] = true;
			ans++;
			sx = nx, sy = ny;
		}
		else {
			int nx = sx + gox[0];
			int ny = sy + goy[0];
			if (nx < 0 || nx>10 || ny < 0 || ny>10) continue;
			if (visited[sx][sy][nx][ny] || visited[nx][ny][sx][sy]) {
				sx = nx, sy = ny;
				continue;
			}
			visited[sx][sy][nx][ny] = true;
			ans++;
			sx = nx, sy = ny;
		}
	}

	int answer = ans;
	return answer;
}