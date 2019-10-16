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
#define mod 1000000009
#define lim 1000000000
typedef pair < int,int > P;
typedef pair<int,pair<int, int>> PP;
typedef pair<pair<int, int>, pair<int, int>> PPP;
int gox[4] = { -1,1,0,0 };
int goy[4] = { 0,0,-1,1 };
int t, Case = 1, n, m,k;
vector<PPP> v;
//1:상,2:하,3:좌,4:우
int bfs() {
	queue<PPP> q;
	for (int i = 0; i < v.size(); i++) {
		q.push(v[i]);
	}
	for (int i = 1; i <= m; i++) {
		queue<PPP> temp;
		bool visited[105][105] = { false, };
		map<P, int> m,newdir;
		while (!q.empty()) {
			int cnt = q.front().first.first;
			int dir = q.front().first.second;
			int x = q.front().second.first;
			int y = q.front().second.second;
			q.pop();
			int nx = x + gox[dir];
			int ny = y + goy[dir];
			if (nx <= 0 || nx >= n - 1 || ny <= 0 || ny >= n - 1) { //가장자리
				int newcnt = cnt / 2;
				if (newcnt == 0) continue;
				if (dir == 0 || dir == 1) {
					dir = 1 - dir;
					temp.push({ { newcnt,dir }, { nx,ny } });
				}
				else {
					dir = 5 - dir;
					temp.push({ { newcnt,dir },{ nx,ny } });
				}
			}
			else { // 그외
				temp.push({ { cnt,dir }, { nx,ny } });
			}
		}
		int Max[105][105] = { 0, };
		while (!temp.empty()) {
			int cnt = temp.front().first.first;
			int dir = temp.front().first.second;
			int x = temp.front().second.first;
			int y = temp.front().second.second;
			temp.pop();
			if (m.count({ x,y }) == 0) {
				m[{x, y}] = cnt;
				Max[x][y] = cnt;
				newdir[{x, y}] = dir;
			}
			else {
				if (Max[x][y]< cnt) {
					Max[x][y] = cnt;
					newdir[{x, y}] = dir;
				}
				m[{x, y}] += cnt;
			}
		}

		map<P, int>::iterator it;
		for (it = m.begin(); it != m.end(); it++) {
			q.push({ {it->second,newdir[it->first]}, { it->first.first, it->first.second } });
		}
	}
	int ans = 0;
	while (!q.empty()) {
		ans += q.front().first.first;
		q.pop();
	}
	return ans;
}
int main(void) {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &n, &m, &k);
		v.clear();
		for (int i = 1; i <= k; i++) {
			int x, y, cnt, dir;
			scanf("%d%d%d%d", &x, &y, &cnt, &dir);
			v.push_back({ {cnt,dir-1 }, { x,y} });
		}
		printf("#%d %d\n", Case++, bfs());
	}
	return 0;
}