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
int gox[4] = {-1,0,1,0 };
int goy[4] = {0,1,0,-1 };
int n,ans=1e9;
vector<P> v,temp;
bool visited[105];
int board[11][11];
void go(int index, int cnt, int depth) {
	if (cnt == depth) {
		map<P, int> m;
		int no = 0;
		for (int j = 0; j < temp.size(); j++) {
			int x = temp[j].first, y = temp[j].second;
			m[{x, y}]++;
			if (m[{x, y}] >= 2) {
				no = 1;
				break;
			}
			for (int i = 0; i < 4; i++) {
				int nx = x + gox[i];
				int ny = y + goy[i];
				if (nx<1 || nx>n || ny<1 || ny>n) {
					no = 1;
					break;
				}
				m[{nx, ny}]++;
				if (m[{nx, ny}] >= 2) {
					no = 1;
					break;
				}
			}
			if (no) break;
		}
		if (!no) {
			map<P, int>::iterator it;
			int sum = 0;
			for (it = m.begin(); it != m.end(); it++) {
				sum += board[it->first.first][it->first.second];
			}
			ans = min(ans, sum);
		}
		return;
	}

	for (int i = index; i < v.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			temp.push_back({v[i].first,v[i].second });
			go(i + 1, cnt + 1, depth);
			temp.pop_back();
			visited[i] = false;
		}
	}
}
int main(void) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf(" %d", &board[i][j]);
			v.push_back({ i,j });
		}
	}
	go(0, 0, 3);
	printf("%d\n", ans);
	return 0;
}